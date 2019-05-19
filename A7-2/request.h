#ifndef _REQUEST_H_
#define _REQUEST_H_
#include <iostream>
#include <vector>
#include <string>
#include "gerdabify.h"
#include "exception.h"
#include "gerdabServer.hpp"
using namespace std;

class LoginUsers{
public:
    void add_user(string name , string pass);
    bool has_this_user(string name);
    List get_user_info(string name);
private:
    vector<string> users;
    vector<string>passwords;
};

class LogInHandler: public RequestHandler{
public:
    LogInHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames);
    void callback(Request* req , Response* res);
private:
    GerdabifyAPI* gerdab;
    LoginUsers* usernames;
};

class SignUpHandler: public RequestHandler{
public:
    SignUpHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames);
    void callback(Request* req , Response* res);
    void signup_page();
private:
    GerdabifyAPI* gerdab;
    LoginUsers* usernames;
};
class PlayListsHandler: public RequestHandler{
public:
    PlayListsHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames);
    void callback(Request* req , Response* res);
private:
    GerdabifyAPI* gerdab;
    LoginUsers* usernames;
};

class ArtistsHandler: public RequestHandler{
public:
    ArtistsHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames);
    void callback(Request* req , Response* res);
private:
    GerdabifyAPI* gerdab;
    LoginUsers* usernames;
};

class AlbumsHandler: public RequestHandler{
public:
    AlbumsHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames);
    void callback(Request* req , Response* res);
private:
    GerdabifyAPI* gerdab;
    LoginUsers* usernames;
};

class MusicsHandler: public RequestHandler{
public:
    MusicsHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames);
    void callback(Request* req , Response* res);
private:
    GerdabifyAPI* gerdab;
    LoginUsers* usernames;
};

class SearchHandler: public RequestHandler{
public:
    SearchHandler(GerdabifyAPI& gerdabify , LoginUsers& _usernames);
    void callback(Request* req , Response* res);
private:
    GerdabifyAPI* gerdab;
    LoginUsers* usernames;
};
class HomePageHandler: public RequestHandler{
    void callback(Request* req, Response* res);
};
class SignUpPage: public RequestHandler{
    void callback(Request* req, Response* res);
};
class LogInPage: public RequestHandler{
    void callback(Request* req, Response* res);
};

class PlayListPage: public RequestHandler{
    void callback(Request* req, Response* res);
};

class ArtistPage: public RequestHandler{
    void callback(Request* req, Response* res);
};

class MusicPage: public RequestHandler{
    void callback(Request* req, Response* res);
};

class AlbumPage: public RequestHandler{
    void callback(Request* req, Response* res);
};

class SearchPage: public RequestHandler{
    void callback(Request* req, Response* res);
};
#endif