#include <iostream>
#include <map>
#include <string>
#include "gerdabify.h"
#include "request.h"

int main(int argc, const char* argv[]) {
    try {
        Server server;
        static LoginUsers usernames;
        static GerdabifyAPI gerdabify;

        RequestHandler* home = new HomePageHandler();
        RequestHandler* signup_page = new SignUpPage();
        RequestHandler* login_page = new LogInPage();
        RequestHandler* playlist_page = new PlayListPage();
        RequestHandler* artist_page = new ArtistPage();
        RequestHandler* album_page = new AlbumPage();
        RequestHandler* music_page = new MusicPage();
        RequestHandler* search_page = new SearchPage();

        RequestHandler* signup = new SignUpHandler(gerdabify , usernames);
        PlayListsHandler* playlists=new PlayListsHandler(gerdabify , usernames);
        RequestHandler* login = new LogInHandler(gerdabify , usernames);
        RequestHandler* artists = new ArtistsHandler(gerdabify , usernames);
        RequestHandler* albums = new AlbumsHandler(gerdabify , usernames);
        RequestHandler* musics = new MusicsHandler(gerdabify , usernames);
        RequestHandler* search = new SearchHandler(gerdabify , usernames);

 


        server.get("/home", home);
        server.get("/signup" ,signup);
        server.get("/login" ,login);
        server.get("/playlists",playlists);
        server.get("/artists" , artists);
        server.get("/albums" , albums);
        server.get("/musics" , musics);
        server.get("/search" , search);
        server.get("/signup_page", signup_page);
        server.get("/login_page", login_page);
        server.get("/playlist_page", playlist_page);
        server.get("/artist_page", artist_page);
        server.get("/album_page", album_page);
        server.get("/music_page", music_page);
        server.get("/search_page", search_page);

        cout << "Listening on port 5000" << endl;
        server.start(5000);
    } catch(Exception e) {
        cerr << "WebServer: " << e.getMessage() << endl;
    }

    return EXIT_SUCCESS;
}
