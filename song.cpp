#include <iostream>
#include <string>
using namespace std;

// Base class Song
class Song {
protected:
    string name;
    string lyrics;

public:
    // Constructor for Song class
    Song(string n, string l) : name(n), lyrics(l) {}

    // Virtual play method to be overridden by derived classes
    virtual void play() = 0;

    // Display basic song information
    void displayInfo() {
        cout << "Song Name: " << name << endl;
        cout << "Lyrics: " << lyrics << endl;
    }

    // Getter for song name (used for removal in Playlist)
    string getName() const {
        return name;
    }
};

// Derived class MP3
class MP3 : public Song {
protected:
    string genre;

public:
    // Constructor for MP3 class
    MP3(string n, string l, string g) : Song(n, l), genre(g) {}

    // Overriding play method for MP3
    void play() override {
        cout << "Playing MP3: " << name << " (" << genre << " genre)" << endl;
        cout << "Lyrics: " << lyrics << endl;
    }
};

// Derived class MP4
class MP4 : public Song {
protected:
    string videoDescription;

public:
    // Constructor for MP4 class
    MP4(string n, string l, string v) : Song(n, l), videoDescription(v) {}

    // Overriding play method for MP4
    void play() override {
        cout << "Playing MP4: " << name << endl;
        cout << "Lyrics: " << lyrics << endl;
        cout << "Video: " << videoDescription << endl;
    }
};

// Derived class sMP4 (Secret MP4)
class sMP4 : public MP4 {
public:
    // Constructor for sMP4 class
    sMP4(string n, string l, string v) : MP4(n, l, v) {}

    // Overriding play method for sMP4 (with secret handling)
    void play() override {
        cout << "Playing sMP4: " << name << endl;
        cout << "Bleeping out the lyrics: BLEEP BLEEP" << endl;
        cout << "Glitching the video: Glitchy glitchy... visual disturbances" << endl;
    }
};

// Playlist class to store songs
class Playlist {
private:
    Song* songs[10];  // Fixed-size array to store up to 10 songs
    int songCount;     // To track the number of songs in the playlist

public:
    // Constructor
    Playlist() : songCount(0) {}

    // Add song to the playlist
    void addSong(Song* song) {
        if (songCount < 10) {
            songs[songCount] = song;
            songCount++;
        } else {
            cout << "Playlist is full! Cannot add more songs." << endl;
        }
    }

    // Remove song from the playlist by name
    void removeSong(string songName) {
        bool found = false;
        for (int i = 0; i < songCount; ++i) {
            if (songs[i]->getName() == songName) {
                found = true;
                for (int j = i; j < songCount - 1; ++j) {
                    songs[j] = songs[j + 1];  // Shift songs left
                }
                songCount--;
                break;
            }
        }
        if (!found) {
            cout << "Song not found in the playlist." << endl;
        }
    }

    // Play all songs in the playlist
    void playAll() {
        for (int i = 0; i < songCount; ++i) {
            songs[i]->displayInfo();
            songs[i]->play();
            cout << endl;
        }
    }
};

// Main function
int main() {
    // Create some song objects
    MP3 song1("Shape of You", "The club isn't the best place to find a lover", "Pop");
    MP4 song2("Bohemian Rhapsody", "Is this the real life?", "Classic Rock video with dramatic scenes");
    sMP4 song3("Secret Song", "This is a secret", "Unknown video description");

    // Create playlist and add songs
    Playlist playlist;
    playlist.addSong(&song1);
    playlist.addSong(&song2);
    playlist.addSong(&song3);

    // Play all songs
    playlist.playAll();

    // Remove a song by name
    playlist.removeSong("Shape of You");

    // Play remaining songs after removal
    cout << "After removing 'Shape of You':\n" << endl;
    playlist.playAll();

    return 0;
}
