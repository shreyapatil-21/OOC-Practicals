#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdio> // For remove() and rename()

using namespace std;

// --- Data Structure (Class) for a single Booking/Ticket ---
class Ticket {
private:
    // Using fixed-size char arrays is necessary for direct binary file I/O
    int booking_id;
    char movie_name[50];
    char customer_name[50];
    int num_tickets;
    double total_price;

public:
    // Constructor
    Ticket() : booking_id(0), num_tickets(0), total_price(0.0) {
        movie_name[0] = '\0';
        customer_name[0] = '\0';
    }

    // Function to get booking details from user
    void create_booking() {
        cout << "\n--- New Booking ---" << endl;
        cout << "Enter Booking ID (e.g., 101): ";
        // Using cin >> int is fine here
        cin >> booking_id;
        // Consume the newline character left by cin>>int before using getline
        cin.ignore(); 

        cout << "Enter Movie Name: ";
        // Use cin.getline for strings with spaces
        cin.getline(movie_name, 50);

        cout << "Enter Customer Name: ";
        cin.getline(customer_name, 50);

        cout << "Enter Number of Tickets: ";
        cin >> num_tickets;

        // Simple pricing logic
        const double TICKET_PRICE = 15.00;
        total_price = num_tickets * TICKET_PRICE;
        cout << fixed << setprecision(2);
        cout << "Total Price: $" << total_price << endl;
    }

    // Function to display booking details to console
    void show_booking() const {
        cout << left << setw(10) << booking_id
             << setw(25) << movie_name
             << setw(25) << customer_name
             << setw(10) << num_tickets
             << "$" << total_price << endl;
    }

    // Getter for Booking ID
    int get_booking_id() const {
        return booking_id;
    }

    // Function to write data in TEXT format for easy viewing/reporting
    void write_to_text(ofstream& text_file) const {
        // Using the insertion operator (<<) formats the data as human-readable text
        text_file << "ID: " << booking_id 
                  << " | Movie: " << movie_name 
                  << " | Customer: " << customer_name 
                  << " | Tickets: " << num_tickets 
                  << " | Price: $" << fixed << setprecision(2) << total_price << endl;
    }
};

// --- Function Prototypes ---
void write_booking();
void display_all_bookings();
void delete_booking(int id);
void export_bookings_to_text();
void display_menu();

// --- Main Function ---
int main() {
    display_menu();
    return 0;
}

// --- Menu and Main Logic ---
void display_menu() {
    int choice;
    do {
        cout << "\n==============================================";
        cout << "\n\tCINEMA TICKET BOOKING SYSTEM" << endl;
        cout << "==============================================";
        cout << "\n1. Book a Ticket";
        cout << "\n2. View All Bookings";
        cout << "\n3. Delete a Booking";
        cout << "\n4. Export Bookings to Text File (Report)";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0; 
        }

        switch (choice) {
            case 1:
                write_booking();
                break;
            case 2:
                display_all_bookings();
                break;
            case 3: {
                int id_to_delete;
                cout << "\nEnter Booking ID to delete: ";
                cin >> id_to_delete;
                delete_booking(id_to_delete);
                break;
            }
            case 4:
                export_bookings_to_text();
                break;
            case 5:
                cout << "\nExiting System. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}

// Function to write a new booking record to the binary file
void write_booking() {
    Ticket new_ticket;
    new_ticket.create_booking();

    fstream file("bookings.dat", ios::out | ios::app | ios::binary);
    
    if (!file.is_open()) {
        cout << "Error: Unable to open file for writing!" << endl;
        return;
    }

    // Write the entire object (raw memory) to the file
    file.write(reinterpret_cast<char*>(&new_ticket), sizeof(new_ticket));
    file.close();
    cout << "\nBooking successfully saved to bookings.dat!" << endl;
}

void display_all_bookings() {
    Ticket ticket;
    
    fstream file("bookings.dat", ios::in | ios::binary);
    
    if (!file.is_open()) {
        cout << "\nNo bookings file (bookings.dat) found yet!" << endl;
        return;
    }

    cout << "\n==========================================================================" << endl;
    cout << "                         ALL BOOKINGS (from bookings.dat)" << endl;
    cout << "==========================================================================" << endl;
    cout << left << setw(10) << "ID"
         << setw(25) << "Movie"
         << setw(25) << "Customer"
         << setw(10) << "Tickets"
         << "Price" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    bool found = false;
    while (file.read(reinterpret_cast<char*>(&ticket), sizeof(ticket))) {
        ticket.show_booking();
        found = true;
    }

    if (!found) {
        cout << "No valid bookings found in the file." << endl;
    }

    file.close();
    cout << "==========================================================================" << endl;
}

void delete_booking(int id) {
    Ticket ticket;
    
    fstream fin("bookings.dat", ios::in | ios::binary);
    
    if (!fin.is_open()) {
        cout << "\nError: No bookings file found to delete from." << endl;
        return;
    }

    fstream fout("temp.dat", ios::out | ios::binary);

    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&ticket), sizeof(ticket))) {
        if (ticket.get_booking_id() != id) {
            fout.write(reinterpret_cast<char*>(&ticket), sizeof(ticket));
        } else {
            found = true;
        }
    }

    fin.close();
    fout.close();


    remove("bookings.dat"); 
    rename("temp.dat", "bookings.dat"); 

    if (found) {
        cout << "\nBooking ID " << id << " successfully deleted and file updated." << endl;
    } else {
        cout << "\nBooking ID " << id << " not found." << endl;
    }
}


//  Text File Export Function 

void export_bookings_to_text() {
    Ticket ticket;
    
    ifstream fin("bookings.dat", ios::in | ios::binary);
    if (!fin.is_open()) {
        cout << "\nNo binary booking file (bookings.dat) found to export." << endl;
        return;
    }

    ofstream fout("bookings_report.txt", ios::out); 
    if (!fout.is_open()) {
        cout << "\nError: Could not create the text report file." << endl;
        fin.close();
        return;
    }

    fout << "--- CINEMA TICKET BOOKING REPORT (Human Readable) ---" << endl;
    fout << "-----------------------------------------------------" << endl;

    // Read records one by one 
    while (fin.read(reinterpret_cast<char*>(&ticket), sizeof(ticket))) {
        ticket.write_to_text(fout);
    }

    fin.close();
    fout.close();
    cout << "\nSuccessfully exported all bookings to 'bookings_report.txt'!" << endl;
}