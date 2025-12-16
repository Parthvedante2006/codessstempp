#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* prev;
    Song* next;
};

Song* head = NULL;
Song* current = NULL;

// Add song at end
void addSong(string name) {
    Song* newSong = new Song();
    newSong->name = name;
    newSong->next = NULL;
    newSong->prev = NULL;

    if (head == NULL) {
        head = newSong;
        current = newSong;
    } else {
        Song* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newSong;
        newSong->prev = temp;
    }
    cout << "Song added: " << name << endl;
}

// Play current song
void playSong() {
    if (current == NULL)
        cout << "Playlist is empty\n";
    else
        cout << "Playing: " << current->name << endl;
}

// Play next song
void nextSong() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        playSong();
    } else {
        cout << "No next song\n";
    }
}

// Play previous song
void prevSong() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        playSong();
    } else {
        cout << "No previous song\n";
    }
}

// Delete current song
void deleteSong() {
    if (current == NULL) {
        cout << "No song to delete\n";
        return;
    }

    Song* temp = current;

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    current = (current->next != NULL) ? current->next : current->prev;

    cout << "Deleted song: " << temp->name << endl;
    delete temp;
}

int main() {
    int choice;
    string name;

    do {
        cout << "\n1. Add Song";
        cout << "\n2. Play Song";
        cout << "\n3. Next Song";
        cout << "\n4. Previous Song";
        cout << "\n5. Delete Song";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, name);
            addSong(name);
            break;
        case 2:
            playSong();
            break;
        case 3:
            nextSong();
            break;
        case 4:
            prevSong();
            break;
        case 5:
            deleteSong();
            break;
        }
    } while (choice != 6);

    return 0;
}
