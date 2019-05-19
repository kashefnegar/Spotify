#include "request.h"


void LoginUsers::add_user(string name , string pass)
{
    if(!has_this_user(name))
    {
        users.push_back(name);
        passwords.push_back(pass);
    }
}

bool LoginUsers::has_this_user(string name)
{
    for(int i =0 ; i<users.size() ; i++)
   		if(users[i] == name)
            return true;        
        return false;
}

List LoginUsers::get_user_info(string name)
{
    List temp;
    temp.push_back(name);
    for(int i =0 ; i<users.size() ; i++)
        if(users[i] == name)
            temp.push_back(passwords[i]);
    return temp;
}
LogInHandler::LogInHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames)
{
    gerdab=new GerdabifyAPI();
    gerdab=&gerdabify;
    usernames = new LoginUsers();
    usernames =& _usernames;
}
void LogInHandler::callback(Request* req , Response* res)
{
    try{
        if(req->getParam("username") == "")
            throw 1;
        if(req->getParam("password") == "")
            throw 2;
        gerdab->login(req->getParam("username") , req->getParam("password"));
        usernames->add_user(req->getParam("username") , req->getParam("password"));
        res->body << "<body><p><h2>Welcome!</h2></p></body>";
    }
    catch(InvalidCredentials ex)
    {
        res->body << "<body><p><h2>Have you registered yet?</h2><h3>if yes, make sure you are using correct username and password</h3></p></body>";
    }
    catch (int a)
    {
        if (a==1)
            res->body << "<body><p><h2>Please enter your username</h2></p></body>";
        else if(a==2)
            res->body << "<body><p><h2>Please enter your password</h2></p></body>";
    }
    res->body <<"<head><style>.btn-group .button {background-color: #4CAF50; /* Green */border: none;color: white;padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;cursor: pointer;float: left;}";
    res->body <<".btn-group .button:hover {background-color: #3e8e41;}body {background-color: lightgreen;}</style></head>";
    res->body <<"<body><div class=btn-group>";
    res->body <<"<form action=/home><button class=button>Home</button></form>";
    res->body <<"<form action=/login_page><button class=button>Back</button></form>";
    res->body <<"</div></body>";
}


SignUpHandler::SignUpHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames)
{
    gerdab=new GerdabifyAPI();
    usernames=new LoginUsers();
    gerdab=&gerdabify;
    usernames=&_usernames;
}
void SignUpHandler::callback(Request* req , Response* res)
{
    res->body <<"<head><style>.btn-group .button {background-color: #4CAF50; /* Green */border: none;color: white;padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;cursor: pointer;float: left;}";
    res->body <<".btn-group .button:hover {background-color: #3e8e41;}body {background-color: lightgreen;}</style></head>";
    try{
        UserData new_data;
        if(req->getParam("firstname")=="")
            throw 1;
        new_data.firstname = req->getParam("firstname");
        if(req->getParam("lastname") == "")
            throw 2;
        new_data.lastname = req->getParam("lastname") ;
        if(req->getParam("username")=="")
            throw 3;
        new_data.username = req->getParam("username") ;
        if(req->getParam("userType") == "artist")
            new_data.userType = _Artist;
        else if(req->getParam("userType") == "admin")
            new_data.userType = _Admin;
        else if(req->getParam("userType") == "editor")
            new_data.userType = _Editor;
        else if(req->getParam("userType")=="")
            throw 4;
        else
            throw 5;
        if(req->getParam("password") == "")
            throw 6;
        gerdab->signup( new_data , req->getParam("password") );
        res->body << "<body><h2>Welcome!</h2><h2>Now you need to login :)</h2></body>";
        res->body <<"<body><div class=btn-group>";
        res->body <<"<form action=/login_page><button class=button>Login</button></form></div></body>";
    }
    catch(AlreadyExists ex)
    {
        res->body << "<body><h2>The username exists</h2></body>";
    }
    catch(int a)
    {
        if(a==1)
            res->body << "<body><h2>Please enter your firstname</h2></body>";
        else if(a==2)
            res->body << "<body><h2>Please enter your lastname</h2></body>";
        else if(a==3)
            res->body << "<body><h2>Please enter your username</h2></body>";
        else if(a==4)
            res->body << "<body><h2>Please enter your userType</h2></body>";
        else if(a==5)
            res->body << "<body><h2>The userType shoulb be artist , admin or editor</h2></body>";
        else if(a==6)
            res->body << "<body><h2>Please enter your password</h2></body>";
    }
    res->body <<"<body><div class=btn-group>";
    res->body <<"<form action=/home><button class=button>Home</button></form>";
    res->body <<"<form action=/signup_page><button class=button>Back</button></form>";
    res->body <<"</div></body>";
}


PlayListsHandler::PlayListsHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames)
{
    gerdab=new GerdabifyAPI();
    usernames = new LoginUsers();
    gerdab=&gerdabify;
    usernames =& _usernames;
}
void PlayListsHandler::callback(Request* req , Response* res)
{
    res->body <<"<head><style>.btn-group .button {background-color: #4CAF50; /* Green */border: none;color: white;padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;cursor: pointer;float: left;}";
    res->body <<".btn-group .button:hover {background-color: #3e8e41;}body {background-color: lightgreen;}</style></head>";
    try{
        gerdab->enterBrowserMode();
        gerdab->goToHome();
        if(req->getParam("token") == "")
            throw 1;
        if( usernames->has_this_user(req->getParam("token")) )
        {
            List userInfo=usernames->get_user_info(req->getParam("token"));
            gerdab->login(userInfo[0] , userInfo[1]);
            if(req->getParam("name") == "")
                throw 2;
            gerdab->createPlaylist(req->getParam("name"));
            res->body << "<body><h2>Your playlist created :)</h2></body>";
        }
        else
            throw 3;
    }
    catch(AlreadyExists ex)
    {
        res->body << "<body><h2>This playlist has been already created</h2></body>";
    }
    catch (int a)
    {
        if (a==1)
            res->body << "<body><h2>Please enter your username</h2></body>";
        else if(a==2)
        {
            gerdab->goToPlayLists();
            List a = gerdab->listPlaylists();
            if(a.size() > 0)
            {
                res->body<<"<head><style>";
                res->body<<"#customers {font-family: Trebuchet MS, Arial, Helvetica, sans-serif;border-collapse: collapse;width: 100%;}";
                res->body<<"#customers td, #customers th {border: 1px solid #ddd;padding: 8px;}";
                res->body<<"#customers tr:nth-child(even){background-color: #f2f2f2;}";
                res->body<<"#customers tr:hover {background-color: #ddd;}";
                res->body<<"#customers th {padding-top: 12px;padding-bottom: 12px;text-align: left;background-color: #4CAF50;color: white;}</style></head>";
                res->body<<"<body>";
                res->body<<"<table id=customers><tr><th>Username</th><th>PlayList name</th></tr>";
                for(int i=0 ; i<a.size() ; i++)
                    res->body<< "<tr><td>"<<req->getParam("token") <<"</td><td>"<<a[i]<<"</td></tr>";
                res->body<<"</table></body>";
            }
            else
                res->body << "<body><h2>No playlists found</h2></body>";
        }
        else if(a==3)
        {
            res->body << "<body><h2>Login first!</h2></body>";
            res->body <<"<body><div class=btn-group>";
            res->body <<"<form action=/login_page><button class=button>Login</button></form></div></body>";
        }
    }
    
    res->body <<"<body><div class=btn-group>";
    res->body <<"<form action=/home><button class=button>Home</button></form>";
    res->body <<"<form action=/playlist_page><button class=button>Back</button></form>";
    res->body <<"</div></body>";
}


ArtistsHandler::ArtistsHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames)
{
    gerdab=new GerdabifyAPI();
    usernames = new LoginUsers();
    gerdab=&gerdabify;
    usernames =& _usernames;
}
void ArtistsHandler::callback(Request* req , Response* res)
{
    res->body <<"<head><style>.btn-group .button {background-color: #4CAF50; /* Green */border: none;color: white;padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;cursor: pointer;float: left;}";
    res->body <<".btn-group .button:hover {background-color: #3e8e41;}body {background-color: lightgreen;}</style></head>";
    try{
        gerdab->enterBrowserMode();
        gerdab->goToHome();
        gerdab->goToLibrary();
        if(req->getParam("token") == "")
            throw 1;
        if( usernames->has_this_user(req->getParam("token")) )
        {
            List a = gerdab->list();
            if(a.size() > 0 )
            {
                res->body<<"<head><style>";
                res->body<<"#customers {font-family: Trebuchet MS, Arial, Helvetica, sans-serif;border-collapse: collapse;width: 100%;}";
                res->body<<"#customers td, #customers th {border: 1px solid #ddd;padding: 8px;}";
                res->body<<"#customers tr:nth-child(even){background-color: #f2f2f2;}";
                res->body<<"#customers tr:hover {background-color: #ddd;}";
                res->body<<"#customers th {padding-top: 12px;padding-bottom: 12px;text-align: left;background-color: #4CAF50;color: white;}</style></head>";
                res->body<<"<body>";
                res->body<<"<table id=customers><tr><th>Artist name</th></tr>";
                for(int i=0 ; i<a.size() ; i++)
                    res->body<< "<tr><td>"<<a[i]<<"</td></tr>";
                res->body<<"</table></body>";
            }
            else
                res->body << "<body><h2>No artists found</h2></body>";
        }
        else
            throw 2;
    }
    catch (int a)
    {
        if (a==1)
            res->body << "<body><h2>Please enter your username</h2></body>";
        else if(a==2)
        {
            res->body << "<body><h2>Login first!</h2></body>";
            res->body <<"<body><div class=btn-group>";
            res->body <<"<form action=/login_page><button class=button>Login</button></form></div></body>";
        }
    }
    res->body <<"<body><div class=btn-group>";
    res->body <<"<form action=/home><button class=button>Home</button></form>";
    res->body <<"<form action=/artist_page><button class=button>Back</button></form>";
    res->body <<"</div></body>";
}



AlbumsHandler::AlbumsHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames)
{
    gerdab=new GerdabifyAPI();
    usernames = new LoginUsers();
    gerdab=&gerdabify;
    usernames =& _usernames;
}
void AlbumsHandler::callback(Request* req , Response* res)
{
    res->body <<"<head><style>.btn-group .button {background-color: #4CAF50; /* Green */border: none;color: white;padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;cursor: pointer;float: left;}";
    res->body <<".btn-group .button:hover {background-color: #3e8e41;}body {background-color: lightgreen;}</style></head>";
    try{
        gerdab->enterBrowserMode();
        gerdab->goToHome();
        gerdab->goToLibrary();
        if(req->getParam("token") == "")
            throw 1;
        if( usernames->has_this_user(req->getParam("token")) )
        {
            List a = gerdab->listAlbumsCompName();
            if(a.size() > 0)
            {
                res->body<<"<head><style>";
                res->body<<"#customers {font-family: Trebuchet MS, Arial, Helvetica, sans-serif;border-collapse: collapse;width: 100%;}";
                res->body<<"#customers td, #customers th {border: 1px solid #ddd;padding: 8px;}";
                res->body<<"#customers tr:nth-child(even){background-color: #f2f2f2;}";
                res->body<<"#customers tr:hover {background-color: #ddd;}";
                res->body<<"#customers th {padding-top: 12px;padding-bottom: 12px;text-align: left;background-color: #4CAF50;color: white;}</style></head>";
                res->body<<"<body>";
                res->body<<"<table id=customers><tr><th>Artist name</th><th>Album name</th></tr>";
                for(int i=0 ; i<a.size() ; i++)
                {    
                    string album_name = a[i];
                    string t="-";
                    string artist_name = album_name.substr(0, album_name.find(t));
                    album_name.erase(0, album_name.find(t) + t.length()); 
                    res->body<< "<tr><td>"<<artist_name<<"</td><td>"<<album_name<<"</tr>";
                }
                res->body<<"</table></body>";
            }
            else
                res->body << "<body><h2>No albums found</h2></body>";
        }
        else
            throw 2;
    }
    catch (int a)
    {
        if (a==1)
            res->body << "<body><h2>Please enter your username</h2></body>";
        else if(a==2)
        {
            res->body << "<body><h2>Login first!</h2></body>";
            res->body <<"<body><div class=btn-group>";
            res->body <<"<form action=/login_page><button class=button>Login</button></form></div></body>";
        }
    }
    res->body <<"<body><div class=btn-group>";
    res->body <<"<form action=/home><button class=button>Home</button></form>";
    res->body <<"<form action=/album_page><button class=button>Back</button></form>";
    res->body <<"</div></body>";
}


MusicsHandler::MusicsHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames)
{
    gerdab=new GerdabifyAPI();
    usernames = new LoginUsers();
    gerdab=&gerdabify;
    usernames =& _usernames;
}
void MusicsHandler::callback(Request* req , Response* res)
{
    res->body <<"<head><style>.btn-group .button {background-color: #4CAF50; /* Green */border: none;color: white;padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;cursor: pointer;float: left;}";
    res->body <<".btn-group .button:hover {background-color: #3e8e41;}body {background-color: lightgreen;}</style></head>";
    try{
        gerdab->enterBrowserMode();
        gerdab->goToHome();
        gerdab->goToLibrary();
        if(req->getParam("token") == "")
            throw 1;
        if( usernames->has_this_user(req->getParam("token")) )
        {
            List a = gerdab->listMusicsCompName();
            if(a.size() > 0)
            {
                res->body<<"<head><style>";
                res->body<<"#customers {font-family: Trebuchet MS, Arial, Helvetica, sans-serif;border-collapse: collapse;width: 100%;}";
                res->body<<"#customers td, #customers th {border: 1px solid #ddd;padding: 8px;}";
                res->body<<"#customers tr:nth-child(even){background-color: #f2f2f2;}";
                res->body<<"#customers tr:hover {background-color: #ddd;}";
                res->body<<"#customers th {padding-top: 12px;padding-bottom: 12px;text-align: left;background-color: #4CAF50;color: white;}</style></head>";
                res->body<<"<body>";
                res->body<<"<table id=customers><tr><th>Artist name</th><th>Album name</th><th>Music name</th></tr>";
                
                for(int i=0 ; i<a.size() ; i++)
                {    
                    string music_name = a[i];
                    string t="-";
                    string artist_name = music_name.substr(0, music_name.find(t));
                    music_name.erase(0, music_name.find(t) + t.length()); 
                    string album_name = music_name.substr(0, music_name.find(t));
                    music_name.erase(0, music_name.find(t) + t.length());
                    res->body<< "<tr><td>"<<artist_name<<"</td><td>"<<album_name<<"</td><td>"<<music_name<<"</td></tr>";
                }
                res->body<<"</table></body>";
            }
            else
                res->body << "<body><h2>No musics found</h2></body>";
        }
        else
            throw 2;
    }
    catch (int a)
    {
        if (a==1)
            res->body << "<body><h2>Please enter your username</h2></body>";
        else if(a==2)
        {
            res->body << "<body><h2>Login first!</h2></body>";
            res->body <<"<body><div class=btn-group>";
            res->body <<"<form action=/login_page><button class=button>Login</button></form></div></body>";
        }
    }
    res->body <<"<body><div class=btn-group>";
    res->body <<"<form action=/home><button class=button>Home</button></form>";
    res->body <<"<form action=/music_page><button class=button>Back</button></form>";
    res->body <<"</div></body>";
}

SearchHandler::SearchHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames)
{
    gerdab=new GerdabifyAPI();
    usernames = new LoginUsers();
    gerdab=&gerdabify;
    usernames =& _usernames;
}
void SearchHandler::callback(Request* req , Response* res)
{
    res->body <<"<head><style>.btn-group .button {background-color: #4CAF50; /* Green */border: none;color: white;padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;cursor: pointer;float: left;}";
    res->body <<".btn-group .button:hover {background-color: #3e8e41;}body {background-color: lightgreen;}</style></head>";
    try{
        gerdab->enterBrowserMode();
        gerdab->goToHome();
        gerdab->goToLibrary();
        if(req->getParam("token") == "")
            throw 1;
        if( usernames->has_this_user(req->getParam("token")) )
        {
            if(req->getParam("keyword") == "")
                throw 3;
            else
            {
                List a = gerdab->listMusicsCompName();
                if(a.size() > 0)
                {
                    res->body<<"<head><style>";
                    res->body<<"#customers {font-family: Trebuchet MS, Arial, Helvetica, sans-serif;border-collapse: collapse;width: 100%;}";
                    res->body<<"#customers td, #customers th {border: 1px solid #ddd;padding: 8px;}";
                    res->body<<"#customers tr:nth-child(even){background-color: #f2f2f2;}";
                    res->body<<"#customers tr:hover {background-color: #ddd;}";
                    res->body<<"#customers th {padding-top: 12px;padding-bottom: 12px;text-align: left;background-color: #4CAF50;color: white;}</style></head>";
                    res->body<<"<body>";
                    res->body<<"<table id=customers><tr><th>Artist name</th><th>Album name</th><th>Music name</th></tr>";
                    for(int i=0 ; i<a.size() ; i++)
                    {    
                        string music_name = a[i];
                        string t="-";
                        string artist_name = music_name.substr(0, music_name.find(t));
                        music_name.erase(0, music_name.find(t) + t.length()); 
                        string album_name = music_name.substr(0, music_name.find(t));
                        music_name.erase(0, music_name.find(t) + t.length());
                        if(music_name == req->getParam("keyword"))
                            res->body<< "<tr><td>"<<artist_name<<"</td><td>"<<album_name<<"</td><td>"<<music_name<<"</td></tr>";
                    }
                    res->body<<"</table></body>";
                }
                else
                    res->body << "<body><h2>No musics found in the library</h2></body>";
            }
        }
        else
            throw 2;
    }
    catch (int a)
    {
        if (a==1)
            res->body << "<body><h2>Please enter your username</h2></body>";
        else if(a==2)
        {
            res->body << "<body><h2>Login first!</h2></body>";
            res->body <<"<body><div class=btn-group>";
            res->body <<"<form action=/login_page><button class=button>Login</button></form></div></body>";
        }
        else if(a==3)
            res->body << "<body><h2>Please enter the music name!</h2></body>";
    }
    res->body <<"<body><div class=btn-group>";
    res->body <<"<form action=/home><button class=button>Home</button></form>";
    res->body <<"<form action=/search_page><button class=button>Back</button></form>";
    res->body <<"</div></body>";
}


void HomePageHandler::callback(Request* req, Response* res)
{
    res->body <<"<head><style>.btn-group .button {background-color: #4CAF50; /* Green */border: none;color: white;padding: 15px 32px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;cursor: pointer;float: left;}";
    res->body <<".btn-group .button:hover {background-color: #3e8e41;}body {background-color: lightgreen;}.center {position: absolute;left: 28%;top: 60%;width: 100%;text-align: center;font-size: 18px;}";
    res->body<<".pos1 {position: absolute;left: -1%;top: 5%;width: 100%;text-align: center;font-size: 18px;}";
    res->body<<".pos2 {position: absolute;left: -1%;top: 45%;width: 100%;text-align: center;font-size: 18px;}</style></head>";
    res->body<<"<div class=pos1><body><img src=https://d1uuigdobp75j5.cloudfront.net/2017/07/21220746/spotify-logo.png alt=spotify width=400 height=400></body></div>";
    res->body<<"<div class=pos2><body><img src=http://digitalspyuk.cdnds.net/16/29/980x490/landscape-1468859256-spotify-logo-rgb-green-1.png alt=Norway width=400 height=150></body></div>";
    res->body <<"<div class=center><body>";
    res->body<<"<div class=btn-group>";
    res->body <<"<form action=/signup_page><button class=button>SignUp</button></form>";
    res->body <<"<form action=/login_page><button class=button>Login</button></form>";
    res->body <<"<form action=/playlist_page><button class=button>Playlist</button></form>";
    res->body <<"<form action=/artist_page><button class=button>Artists</button></form>";
    res->body <<"<form action=/album_page><button class=button>Albums</button></form>";
    res->body <<"<form action=/music_page><button class=button>Musics</button></form>";
    res->body <<"<form action=/search_page><button class=button>Search</button></form>";
    res->body <<"</div></body></div>";
}



void SignUpPage::callback(Request* req, Response* res)
{
    res->body <<"<head><style>input[type=text],input[type=password], select {width: 100%;padding: 12px 20px;margin: 8px 0;display: inline-block;border: 1px solid #ccc;border-radius: 4px;box-sizing: border-box;}";
    res->body <<"input[type=submit] {width: 100;background-color: #4CAF50;color: white;padding: 14px 20px;margin: 8px 0;border: none;border-radius: 4px;cursor: pointer;}";
    res->body <<"input[type=submit]:hover {background-color: #45a049;}";
    res->body<<".pos1 {position: absolute;left: -16%;top: 60%;width: 100%;text-align: center;font-size: 18px;}";
    res->body<<".pos2 {position: absolute;left: 4%;top: 58%;width: 100%;text-align: center;font-size: 18px;}";

    res->body <<"div {position: absolute;left :30%;right: 30%;border-radius: 5px;background-color: none;padding: 20px;}body {background-color: lightgreen;}</style></head>";
    res->body<<"<div class=pos1><body><img src=https://d1uuigdobp75j5.cloudfront.net/2017/07/21220746/spotify-logo.png alt=spotify width=150 height=150></body></div>";
    res->body<<"<div class=pos2><body><img src=http://digitalspyuk.cdnds.net/16/29/980x490/landscape-1468859256-spotify-logo-rgb-green-1.png alt=spotify width=500 height=200></body></div>";
    res->body<<"<body><div><form action=/signup>";
    res->body <<"<label for=firstname>First Name</label>";
    res->body <<"<input type=text id=firstname name=firstname>";
    res->body <<"<label for=lastname>Last Name</label>";
    res->body <<"<input type=text id=lastname name=lastname>";
    res->body <<"<label for=username>Username</label>";
    res->body <<"<input type=text id=username name=username>";
    res->body <<"<label for=password>Password</label>";
    res->body <<"<input type=password id=password name=password>";
    res->body <<"<label for=userType>userType</label>";
    res->body <<"<select id=userType name=userType>";
    res->body <<"<option value=artist>Artist</option>";
    res->body <<"<option value=admin>Admin</option>";
    res->body <<"<option value=editor>Editor</option></select>";
    res->body <<"<input type=submit value=Signup></form></div></body>";
}

void LogInPage::callback(Request* req, Response* res)
{
    res->body <<"<style>input[type=text], input[type=password], select {width: 100%;padding: 12px 20px;margin: 8px 0;display: inline-block;border: 1px solid #ccc;border-radius: 4px;box-sizing: border-box;}";
    res->body <<"input[type=submit] {width: 100;background-color: #4CAF50;color: white;padding: 14px 20px;margin: 8px 0;border: none;border-radius: 4px;cursor: pointer;}";
    res->body <<"input[type=submit]:hover {background-color: #45a049;}";
    res->body<<".pos1 {position: absolute;left: -16%;top: 60%;width: 100%;text-align: center;font-size: 18px;}";
    res->body<<".pos2 {position: absolute;left: 4%;top: 58%;width: 100%;text-align: center;font-size: 18px;}";
    res->body <<"div {position: absolute;left :30%;right: 30%;border-radius: 5px;background-color: none;padding: 20px;}body {background-color: lightgreen;}</style>";
    res->body<<"<div class=pos1><body><img src=https://d1uuigdobp75j5.cloudfront.net/2017/07/21220746/spotify-logo.png alt=spotify width=150 height=150></body></div>";
    res->body<<"<div class=pos2><body><img src=http://digitalspyuk.cdnds.net/16/29/980x490/landscape-1468859256-spotify-logo-rgb-green-1.png alt=spotify width=500 height=200></body></div>";
    res->body <<"<body><div><form action=/login>";
    res->body <<"<label for=username>Username</label>";
    res->body <<"<input type=text id=username name=username>";
    res->body <<"<label for=password>Password</label>";
    res->body <<"<input type=password id=password name=password>";
    res->body <<"<input type=submit value=Login></form></div></body>";
}

void PlayListPage::callback(Request* req, Response* res)
{
    res->body <<"<style>input[type=text], select {width: 100%;padding: 12px 20px;margin: 8px 0;display: inline-block;border: 1px solid #ccc;border-radius: 4px;box-sizing: border-box;}";
    res->body <<"input[type=submit] {width: 120;background-color: #4CAF50;color: white;padding: 14px 20px;margin: 8px 0;border: none;border-radius: 4px;cursor: pointer;}";
    res->body <<"input[type=submit]:hover {background-color: #45a049;}";
    res->body<<".pos1 {position: absolute;left: -16%;top: 60%;width: 100%;text-align: center;font-size: 18px;}";
    res->body<<".pos2 {position: absolute;left: 4%;top: 58%;width: 100%;text-align: center;font-size: 18px;}";
    res->body <<"div {position: absolute;left :30%;right: 30%;border-radius: 5px;background-color: none;padding: 20px;}body {background-color: lightgreen;}</style>";
    res->body<<"<div class=pos1><body><img src=https://d1uuigdobp75j5.cloudfront.net/2017/07/21220746/spotify-logo.png alt=spotify width=150 height=150></body></div>";
    res->body<<"<div class=pos2><body><img src=http://digitalspyuk.cdnds.net/16/29/980x490/landscape-1468859256-spotify-logo-rgb-green-1.png alt=spotify width=500 height=200></body></div>";
    res->body <<"<body><div><form action=/playlists>";
    res->body <<"<label for=token>Username</label>";
    res->body <<"<input type=text id=token name=token>";
    res->body <<"<label for=name>Playlist name</label>";
    res->body <<"<input type=text id=name name=name placeholder="<<"necessary_if_you_want_to_create_a_playlist"<<">";
    res->body <<"<input type=submit value=Create><input type=submit value=MyPlaylists></form></div></body>";
}

void ArtistPage::callback(Request* req, Response* res)
{
    res->body <<"<style>input[type=text], select {width: 100%;padding: 12px 20px;margin: 8px 0;display: inline-block;border: 1px solid #ccc;border-radius: 4px;box-sizing: border-box;}";
    res->body <<"input[type=submit] {width: 120;background-color: #4CAF50;color: white;padding: 14px 20px;margin: 8px 0;border: none;border-radius: 4px;cursor: pointer;}";
    res->body <<"input[type=submit]:hover {background-color: #45a049;}";
    res->body<<".pos1 {position: absolute;left: -16%;top: 60%;width: 100%;text-align: center;font-size: 18px;}";
    res->body<<".pos2 {position: absolute;left: 4%;top: 58%;width: 100%;text-align: center;font-size: 18px;}";
    res->body <<"div {position: absolute;left :30%;right: 30%;border-radius: 5px;background-color: none;padding: 20px;}body {background-color: lightgreen;}</style>";
    res->body<<"<div class=pos1><body><img src=https://d1uuigdobp75j5.cloudfront.net/2017/07/21220746/spotify-logo.png alt=spotify width=150 height=150></body></div>";
    res->body<<"<div class=pos2><body><img src=http://digitalspyuk.cdnds.net/16/29/980x490/landscape-1468859256-spotify-logo-rgb-green-1.png alt=spotify width=500 height=200></body></div>";
    res->body <<"<body><div><form action=/artists>";
    res->body <<"<label for=token>Username</label>";
    res->body <<"<input type=text id=token name=token>";
    res->body <<"<input type=submit value=ShowArtits></form></div></body>";
}

void AlbumPage::callback(Request* req, Response* res)
{
    res->body <<"<style>input[type=text], select {width: 100%;padding: 12px 20px;margin: 8px 0;display: inline-block;border: 1px solid #ccc;border-radius: 4px;box-sizing: border-box;}";
    res->body <<"input[type=submit] {width: 120;background-color: #4CAF50;color: white;padding: 14px 20px;margin: 8px 0;border: none;border-radius: 4px;cursor: pointer;}";
    res->body <<"input[type=submit]:hover {background-color: #45a049;}";
    res->body<<".pos1 {position: absolute;left: -16%;top: 60%;width: 100%;text-align: center;font-size: 18px;}";
    res->body<<".pos2 {position: absolute;left: 4%;top: 58%;width: 100%;text-align: center;font-size: 18px;}";
    res->body <<"div {position: absolute;left :30%;right: 30%;border-radius: 5px;background-color: none;padding: 20px;}body {background-color: lightgreen;}</style>";
    res->body<<"<div class=pos1><body><img src=https://d1uuigdobp75j5.cloudfront.net/2017/07/21220746/spotify-logo.png alt=spotify width=150 height=150></body></div>";
    res->body<<"<div class=pos2><body><img src=http://digitalspyuk.cdnds.net/16/29/980x490/landscape-1468859256-spotify-logo-rgb-green-1.png alt=spotify width=500 height=200></body></div>";
    res->body <<"<body><div><form action=/albums>";
    res->body <<"<label for=token>Username</label>";
    res->body <<"<input type=text id=token name=token>";
    res->body <<"<input type=submit value=ShowAlbums></form></div></body>";
}

void MusicPage::callback(Request* req, Response* res)
{
    res->body <<"<style>input[type=text], select {width: 100%;padding: 12px 20px;margin: 8px 0;display: inline-block;border: 1px solid #ccc;border-radius: 4px;box-sizing: border-box;}";
    res->body <<"input[type=submit] {width: 120;background-color: #4CAF50;color: white;padding: 14px 20px;margin: 8px 0;border: none;border-radius: 4px;cursor: pointer;}";
    res->body <<"input[type=submit]:hover {background-color: #45a049;}";
    res->body<<".pos1 {position: absolute;left: -16%;top: 60%;width: 100%;text-align: center;font-size: 18px;}";
    res->body<<".pos2 {position: absolute;left: 4%;top: 58%;width: 100%;text-align: center;font-size: 18px;}";
    res->body <<"div {position: absolute;left :30%;right: 30%;border-radius: 5px;background-color: none;padding: 20px;}body {background-color: lightgreen;}</style>";
    res->body<<"<div class=pos1><body><img src=https://d1uuigdobp75j5.cloudfront.net/2017/07/21220746/spotify-logo.png alt=spotify width=150 height=150></body></div>";
    res->body<<"<div class=pos2><body><img src=http://digitalspyuk.cdnds.net/16/29/980x490/landscape-1468859256-spotify-logo-rgb-green-1.png alt=spotify width=500 height=200></body></div>";
    res->body <<"<body><div><form action=/musics>";
    res->body <<"<label for=token>Username</label>";
    res->body <<"<input type=text id=token name=token>";
    res->body <<"<input type=submit value=ShowMusics></form></div></body>";
}

void SearchPage::callback(Request* req, Response* res)
{
    res->body <<"<style>input[type=text], select {width: 100%;padding: 12px 20px;margin: 8px 0;display: inline-block;border: 1px solid #ccc;border-radius: 4px;box-sizing: border-box;}";
    res->body <<"input[type=submit] {width: 120;background-color: #4CAF50;color: white;padding: 14px 20px;margin: 8px 0;border: none;border-radius: 4px;cursor: pointer;}";
    res->body <<"input[type=submit]:hover {background-color: #45a049;}";
    res->body<<".pos1 {position: absolute;left: -16%;top: 60%;width: 100%;text-align: center;font-size: 18px;}";
    res->body<<".pos2 {position: absolute;left: 4%;top: 58%;width: 100%;text-align: center;font-size: 18px;}";
    res->body <<"div {position: absolute;left :30%;right: 30%;border-radius: 5px;background-color: none;padding: 20px;}body {background-color: lightgreen;}</style>";
    res->body<<"<div class=pos1><body><img src=https://d1uuigdobp75j5.cloudfront.net/2017/07/21220746/spotify-logo.png alt=spotify width=150 height=150></body></div>";
    res->body<<"<div class=pos2><body><img src=http://digitalspyuk.cdnds.net/16/29/980x490/landscape-1468859256-spotify-logo-rgb-green-1.png alt=spotify width=500 height=200></body></div>";
    res->body <<"<body><div><form action=/search>";
    res->body <<"<label for=token>Username</label>";
    res->body <<"<input type=text id=token name=token>";
    res->body <<"<label for=keyword>Music name</label>";
    res->body <<"<input type=text id=keyword name=keyword>";
    res->body <<"<input type=submit value=Search></form></div></body>";
}

