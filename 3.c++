#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <regex>
#include <fstream>
#include <tuple>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
using namespace std;
class Passenger
{
private:
    std::string name;
    int age;
    std::string gender;
    std::string coachPreferred;
    std::string berthPreferred;
    std::string bookingDate;
    std::string travelingDate;
    std::string status;
    std::string fromStation;
    std::string toStation;
    std::string trainName;
    std::string trainNumber;
    std::string pnr;
    int seatsBooked;
    std::string seatNumber;

public:
    Passenger() {}
    Passenger(const std::string &name, int age, const std::string &gender, const std::string &coachPreferred, const std::string &berthPreferred,
              const std::string &bookingDate, const std::string &travelingDate, const std::string &status, const std::string &fromStation,
              const std::string &toStation, const std::string &trainName, const std::string &trainNumber, const std::string &pnr, int seatsBooked, const std::string &seatNumber)
        : name(name), age(age), gender(gender), coachPreferred(coachPreferred), berthPreferred(berthPreferred),
          bookingDate(bookingDate), travelingDate(travelingDate), status(status), fromStation(fromStation),
          toStation(toStation), trainName(trainName), trainNumber(trainNumber), pnr(pnr), seatsBooked(seatsBooked), seatNumber(seatNumber) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getGender() const { return gender; }
    std::string getCoachPreferred() const { return coachPreferred; }
    std::string getBerthPreferred() const { return berthPreferred; }
    std::string getBookingDate() const { return bookingDate; }
    std::string getTravelingDate() const { return travelingDate; }
    std::string getStatus() const { return status; }
    std::string getFromStation() const { return fromStation; }
    std::string getToStation() const { return toStation; }
    std::string getTrainName() const { return trainName; }
    std::string getTrainNumber() const { return trainNumber; }
    std::string getPnr() const { return pnr; }
    int getSeatsBooked() const { return seatsBooked; }
    std::string getSeatNumber() const { return seatNumber; }

    std::string toString() const
    {
        std::ostringstream oss;
        oss << name << ","
            << age << ","
            << gender << ","
            << coachPreferred << ","
            << berthPreferred << ","
            << bookingDate << ","
            << travelingDate << ","
            << status << ","
            << fromStation << ","
            << toStation << ","
            << trainName << ","
            << trainNumber << ","
            << pnr << ","
            << seatsBooked << ","
            << seatNumber;
        return oss.str();
    }

    static Passenger fromString(const std::string &str)
    {
        std::istringstream iss(str);
        std::string token;
        std::getline(iss, token, ',');
        std::string name = token;
        std::getline(iss, token, ',');
        int age = std::stoi(token);
        std::getline(iss, token, ',');
        std::string gender = token;
        std::getline(iss, token, ',');
        std::string coachPreferred = token;
        std::getline(iss, token, ',');
        std::string berthPreferred = token;
        std::getline(iss, token, ',');
        std::string bookingDate = token;
        std::getline(iss, token, ',');
        std::string travelingDate = token;
        std::getline(iss, token, ',');
        std::string status = token;
        std::getline(iss, token, ',');
        std::string fromStation = token;
        std::getline(iss, token, ',');
        std::string toStation = token;
        std::getline(iss, token, ',');
        std::string trainName = token;
        std::getline(iss, token, ',');
        std::string trainNumber = token;
        std::getline(iss, token, ',');
        std::string pnr = token;
        std::getline(iss, token, ',');
        int seatsBooked = std::stoi(token);
        std::getline(iss, token, ',');
        std::string seatNumber = token;
        return Passenger(name, age, gender, coachPreferred, berthPreferred, bookingDate, travelingDate, status, fromStation, toStation, trainName, trainNumber, pnr, seatsBooked, seatNumber);
    }
    void setPassengerDetails();
    void viewTrainDetails();
    void passengerPanel();
};

void Passenger::viewTrainDetails()
{

    std::vector<std::tuple<std::string, int, std::string, std::string, std::string, std::string, string>> trains = {
        {"Rajdhani Express", 12301, "New Delhi", "Kolkata", "17:10", "08:00", "20"},
        {"Shatabdi Express", 12001, "New Delhi", "Amritsar", "06:00", "12:45", "15"},
        {"Duronto Express", 12201, "Mumbai", "Howrah", "15:15", "07:10", "10"},
        {"Jan Shatabdi Express", 12055, "Coimbatore", "Chennai", "05:30", "08:00", "12"},
        {"Garib Rath", 12345, "Lucknow", "Mumbai", "20:00", "12:30", "25"},
        {"Nizamuddin-Madurai Express", 12683, "Nizamuddin", "Madurai", "22:00", "15:00", "30"},
        {"Udhampur-Mumbai Express", 12477, "Udhampur", "Mumbai", "19:00", "09:00", "20"},
        {"Konkan Kanya Express", 10111, "Lokmanya", "Madgaon", "14:55", "23:45", "10"},
        {"Kerala Express", 12625, "New Delhi", "Kerla", "18:10", "11:30", "18"},
        {"Satyagrah Express", 15273, "Patna", "Ahmedabad", "05:30", "13:30", "15"},
        {"Goa Express", 12780, "Hazrat Nizamuddin", "Vasco da Gama", "15:00", "06:30", "20"},
        {"Howrah Mail", 12809, "Mumbai", "Howrah", "20:35", "05:50", "12"},
        {"Karnataka Express", 12627, "New Delhi", "Bangalore", "21:15", "06:40", "10"},
        {"Gatimaan Express", 12049, "New Delhi", "Agra", "08:10", "09:50", "80"},
        {"Mandovi Express", 10103, "Mumbai", "Madgaon", "07:10", "18:20", "10"},
        {"Tamil Nadu Express", 12621, "New Delhi", "Chennai", "22:30", "07:40", "20"},
        {"Humsafar Express", 22913, "Bandra Terminus", "Patna", "16:55", "20:30", "25"},
        {"Andaman Express", 16031, "Chennai", "Katra", "23:30", "14:10", "18"},
        {"Kamayani Express", 11071, "Lokmanya Tilak", "Varanasi", "12:40", "17:10", "15"},
        {"Matsyagandha Express", 12619, "Lokmanya Tilak", "Mangalore", "15:20", "07:00", "12"},
        {"Sampark Kranti", 12651, "Madurai", "Nizamuddin", "12:50", "15:45", "10"},
        {"Sealdah Rajdhani", 12314, "New Delhi", "Sealdah", "16:30", "10:10", "20"},
        {"Deccan Queen", 12123, "Mumbai", "Pune", "17:10", "20:25", "15"},
        {"Dadar Express", 11058, "Amritsar", "Dadar", "14:45", "20:15", "12"},
        {"Chennai Express", 12610, "Mumbai", "Chennai", "20:30", "19:45", "15"},
        {"Amritsar Shatabdi", 12014, "New Delhi", "Amritsar", "16:30", "22:30", "10"},
        {"Bhopal Express", 12155, "Habibganj", "Hazrat Nizamuddin", "21:00", "08:50", "20"},
        {"Utkal Express", 18477, "Puri", "Haridwar", "20:15", "17:20", "15"},
        
    };
    size_t maxTrainNameWidth = 0;
    size_t maxNumberWidth = 0;
    size_t maxFromWidth = 0;
    size_t maxToWidth = 0;
    size_t maxDepartureWidth = 0;
    size_t maxArrivalWidth = 0;
    size_t maxWaitingListWidth = 0;

    for (const auto &train : trains)
    {
        maxTrainNameWidth = max(maxTrainNameWidth, get<0>(train).length());
        maxNumberWidth = max(maxNumberWidth, to_string(get<1>(train)).length());
        maxFromWidth = max(maxFromWidth, get<2>(train).length());
        maxToWidth = max(maxToWidth, get<3>(train).length());
        maxDepartureWidth = max(maxDepartureWidth, get<4>(train).length());
        maxArrivalWidth = max(maxArrivalWidth, get<5>(train).length());
        maxArrivalWidth = max(maxWaitingListWidth, get<5>(train).length());
    }

    const size_t minColumnWidth = 10;
    const size_t maxColumnWidth = 40;
    maxTrainNameWidth = max(minColumnWidth, min(maxTrainNameWidth, maxColumnWidth));
    maxNumberWidth = max(minColumnWidth, min(maxNumberWidth, maxColumnWidth));
    maxFromWidth = max(minColumnWidth, min(maxFromWidth, maxColumnWidth));
    maxToWidth = max(minColumnWidth, min(maxToWidth, maxColumnWidth));
    maxDepartureWidth = max(minColumnWidth, min(maxDepartureWidth, maxColumnWidth));
    maxArrivalWidth = max(minColumnWidth, min(maxArrivalWidth, maxColumnWidth));
    maxArrivalWidth = max(minColumnWidth, min(maxWaitingListWidth, maxColumnWidth));

    size_t totalWidth = maxTrainNameWidth + maxNumberWidth + maxFromWidth + maxToWidth +
                        maxDepartureWidth + maxArrivalWidth + maxWaitingListWidth + 35;
    cout << BLUE << BOLD << string(totalWidth, '-') << "\n";
    cout << " " << BLUE << BOLD << "                                   -------- Available Train Details --------                     \n"
         << RESET;
    cout << BLUE << BOLD << string(totalWidth, '-') << "\n"
         << RESET;
    cout << CYAN << BOLD
         << left << setw(maxTrainNameWidth) << "Train Name"
         << " | " << setw(maxNumberWidth) << "Number"
         << " | " << setw(maxFromWidth) << "From"
         << " | " << setw(maxToWidth) << "To"
         << " | " << setw(maxDepartureWidth) << "Departure"
         << " | " << setw(maxArrivalWidth) << "Arrival"
         << " | " << setw(maxWaitingListWidth) << "WaitingList" << " |\n"
         << RESET;
    cout << BLUE << BOLD << string(totalWidth, '-') << "\n"
         << RESET;

    for (const auto &train : trains)
    {
        cout << YELLOW << left << setw(maxTrainNameWidth) << get<0>(train) << " | "
             << setw(maxNumberWidth) << get<1>(train) << " | "
             << setw(maxFromWidth) << get<2>(train) << " | "
             << setw(maxToWidth) << get<3>(train) << " | "
             << setw(maxDepartureWidth) << get<4>(train) << " | "
             << setw(maxArrivalWidth) << get<5>(train) << " | "
             << setw(maxWaitingListWidth) << get<6>(train) << "          |\n";
    }

    cout << BLUE << BOLD
         << string(maxTrainNameWidth + maxNumberWidth + maxFromWidth + maxToWidth + maxDepartureWidth + maxArrivalWidth + 35, '-') << "\n"
         << RESET;
}

class Train
{
public:
    std::string generateRandomSeatNumber()
    {
        char seatPrefix = 'A' + rand() % 4;
        int seatNumber = rand() % 100 + 1;
        std::ostringstream seatStream;
        seatStream << seatPrefix << seatNumber;
        return seatStream.str();
    }

private:
    std::map<std::string, int> coachFares;
    std::map<std::string, std::map<std::string, int>> trainFares;
    std::vector<Passenger> passengers;
    std::set<std::string> usedPnrs;
    std::string adminPassword;
    std::map<std::pair<std::string, std::string>, int> distanceMap;

    std::string getCurrentDate() const
    {
        std::time_t now = std::time(0);
        std::tm *ltm = std::localtime(&now);
        std::ostringstream dateStream;
        dateStream << std::setfill('0') << std::setw(2) << ltm->tm_mday << "-"
                   << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon) << "-"
                   << 1900 + ltm->tm_year;
        return dateStream.str();
    }

    bool isValidDate(const std::string &date) const
    {
        std::regex datePattern("\\d{2}-\\d{2}-\\d{4}");
        if (!std::regex_match(date, datePattern))
            return false;

        int day, month, year;
        std::sscanf(date.c_str(), "%d-%d-%d", &day, &month, &year);

        if (month < 1 || month > 12 || day < 1 || day > 31)
            return false;
        if (month == 2 && day > 29)
            return false;
        if (month == 2 && day > 28 && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
            return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;

        return true;
    }

    std::string generateRandomPnr()
    {
        std::string pnr;
        do
        {
            pnr = std::to_string(rand() % 900000000 + 100000000);
        } while (usedPnrs.find(pnr) != usedPnrs.end());
        usedPnrs.insert(pnr);
        return pnr;
    }

    int calculateDistance(const std::string &fromStation, const std::string &toStation) const
    {
        auto it = distanceMap.find({fromStation, toStation});
        if (it != distanceMap.end())
        {
            return it->second;
        }

        it = distanceMap.find({toStation, fromStation});
        if (it != distanceMap.end())
        {
            return it->second;
        }

        return 0;
    }

    int generateRandomFare() const
    {
        return rand() % 500 + 100;
    }

    int calculateSingleSeatFare(const std::string &trainName, const std::string &coach, const std::string &fromStation, const std::string &toStation) const
    {
        auto trainIt = trainFares.find(trainName);
        if (trainIt != trainFares.end())
        {
            auto coachIt = trainIt->second.find(coach);
            if (coachIt != trainIt->second.end())
            {
                int baseFare = coachIt->second;
                int distance = calculateDistance(fromStation, toStation);
                return baseFare + distance;
            }
        }
        return generateRandomFare();
    }

    void loadData()
    {
        std::ifstream inFile("passengerData.txt");
        std::string line;
        while (std::getline(inFile, line))
        {
            if (!line.empty())
            {
                passengers.push_back(Passenger::fromString(line));
            }
        }
        inFile.close();
    }

    void saveData() const
    {
        std::ofstream outFile("passengerData.txt");
        for (const auto &p : passengers)
        {
            outFile << p.toString() << "\n";
        }
        outFile.close();
    }

public:
    Train(const std::string &adminPass) : adminPassword(adminPass)
    {
        coachFares["Sleeper"] = 150;
        coachFares["AC"] = 500;
        coachFares["First Class"] = 1000;

        trainFares["Express"]["Sleeper"] = 150;
        trainFares["Express"]["AC"] = 500;
        trainFares["Express"]["First Class"] = 1000;
        trainFares["Superfast"]["Sleeper"] = 200;
        trainFares["Superfast"]["AC"] = 600;
        trainFares["Superfast"]["First Class"] = 1200;

        distanceMap[{"CityA", "CityB"}] = 100;
        distanceMap[{"CityB", "CityC"}] = 200;
        distanceMap[{"CityA", "CityC"}] = 300;

        loadData();
    }

    ~Train()
    {
        saveData();
    }

    void bookTicket()
    {
        Passenger p;
        int n;
        std::string trainName, trainNumber, fromStation, toStation, travelingDate, coachPreferred, berthPreferred;

        std::cout << YELLOW << BOLD << "Enter the train name: " << RESET;
        std::cin.ignore();
        std::getline(std::cin, trainName);
        trainNumber = std::to_string(rand() % 9000 + 1000);

        std::cout << YELLOW << BOLD << "Enter the source station: " << RESET;
        std::getline(std::cin, fromStation);
        std::cout << YELLOW << BOLD << "Enter the destination station: " << RESET;
        std::getline(std::cin, toStation);

        do
        {
            std::cout << YELLOW << BOLD << "Enter the traveling date (dd-mm-yyyy): " << RESET;
            std::getline(std::cin, travelingDate);
            if (!isValidDate(travelingDate))
            {
                std::cout << RED << BOLD << "Invalid date format. Please try again.\n"
                          << RESET;
            }
        } while (!isValidDate(travelingDate));

        std::cout << YELLOW << BOLD << "Enter the number of seats to book: " << RESET;
        std::cin >> n;
        std::cin.ignore();

        std::cout << YELLOW << BOLD << "Enter your preferred coach (Sleeper, AC, First Class): " << RESET;
        std::getline(std::cin, coachPreferred);
        std::cout << YELLOW << BOLD << "Enter your preferred berth (Upper, Middle, Lower): " << RESET;
        std::getline(std::cin, berthPreferred);

        for (int i = 0; i < n; ++i)
        {
            std::string name, gender, status;
            int age;

            std::cout << GREEN << BOLD << "Enter the name of passenger " << i + 1 << ": " << RESET;
            std::getline(std::cin, name);
            std::cout << GREEN << BOLD << "Enter the age of passenger " << i + 1 << ": " << RESET;
            std::cin >> age;
            std::cin.ignore();

            std::cout << GREEN << BOLD << "Enter the gender of passenger " << i + 1 << " (M/F/O): " << RESET;
            std::getline(std::cin, gender);

            std::string bookingDate = getCurrentDate();

            std::string seatNumber = generateRandomSeatNumber();
            status = "Confirmed";

            int fare = calculateSingleSeatFare(trainName, coachPreferred, fromStation, toStation);
            std::string pnr = generateRandomPnr();
            std::cout << CYAN << BOLD << "Fare for passenger " << i + 1 << ": " << " INR " << fare << "\n"
                      << RESET;
            std::cout << CYAN << BOLD << "PNR " << ": " << pnr << "\n"
                      << RESET;
            passengers.emplace_back(name, age, gender, coachPreferred, berthPreferred, bookingDate, travelingDate, status, fromStation, toStation, trainName, trainNumber, pnr, 1, seatNumber);
        }
        saveData();
    }

    void cancelTicket()
    {
        std::string pnr;
        std::cout << BLUE << BOLD << "Enter the PNR number to cancel the ticket: " << RESET;
        std::cin.ignore();
        std::getline(std::cin, pnr);

        auto it = std::remove_if(passengers.begin(), passengers.end(), [&pnr](const Passenger &p)
                                 { return p.getPnr() == pnr; });

        if (it != passengers.end())
        {
            passengers.erase(it, passengers.end());
            std::cout << GREEN << BOLD << "Ticket with PNR " << pnr << " has been canceled successfully.\n"
                      << RESET;
        }
        else
        {
            std::cout << RED << BOLD << "No ticket found with PNR! " << pnr << ".\n"
                      << RESET;
        }
        saveData();
    }

    void passengerPanel()
    {
        Passenger p;
        int choice;

        std::cout << CYAN << BOLD << "=======================================================================\n";
        std::cout << CYAN << BOLD << "========================== Passenger Panel ===========================\n";
        std::cout << CYAN << BOLD << "=======================================================================\n"
                  << RESET;
        std::cout << RESET;
        std::cout << YELLOW << BOLD << "1. Book Ticket\n";
        std::cout << YELLOW << BOLD << "2. Cancel Ticket\n";
        std::cout << YELLOW << BOLD << "3. View Train Detail\n";

        std::cout << YELLOW << BOLD << "4. Back to Main Menu\n";
        std::cout << BLUE << BOLD << "Enter your choice: " << RESET;
        std::cin >> choice;
        
        switch (choice)
        {
        case 1:
            bookTicket();
            break;
        case 2:
            cancelTicket();
            break;
        case 3:
            p.viewTrainDetails();
            break;
        case 4:
            return;
        default:
            std::cout << RED << BOLD << "Invalid choice! Please try again.\n"
                      << RESET;
            break;
        }
    }

    void adminPanel()
    {
        std::string password;
        std::cout << YELLOW << BOLD << "Enter admin password: " << RESET;
        std::cin.ignore();
        std::getline(std::cin, password);

        if (password == adminPassword)
        {
            std::cout << GREEN << BOLD << "Login successful!\n"
                      << RESET;
            std::cout << CYAN << BOLD << "=======================================================================\n";
            std::cout << CYAN << BOLD << "========================== Admin Panel ===========================\n";
            std::cout << CYAN << BOLD << "=======================================================================\n"
                      << RESET;
            std::cout << RESET;

            int n;
            std::cout << YELLOW << BOLD << "Enter the no. of passenger data you want to print" << RESET;
            std::cin >> n;

            std::cout << CYAN << BOLD << "Passenger Details:\n"
                      << RESET;

            int i = 1;
            for (auto it = passengers.rbegin(); it != passengers.rend(); ++it)
            {
                if (i > n)
                    break;
                const auto &p = *it;
                std::cout << RED << BOLD << "        ==========================passenger -" << i++ << "===================================\n"
                          << RESET;
                std::cout << YELLOW << "Name: " << p.getName() << ", Age: " << p.getAge() << ", Gender: " << p.getGender()
                          << ", Coach: " << p.getCoachPreferred() << ", Berth: " << p.getBerthPreferred()
                          << ", Booking Date: " << p.getBookingDate() << ", Traveling Date: " << p.getTravelingDate()
                          << ", Status: " << p.getStatus() << ", From: " << p.getFromStation()
                          << ", To: " << p.getToStation() << ", Train Name: " << p.getTrainName()<<"\n"
                          << ", Train Number: " << p.getTrainNumber() << ", PNR: " << p.getPnr()
                          << ", Seats Booked: " << p.getSeatsBooked() << ", Seat Number: " << p.getSeatNumber() << "\n"
                          << RESET;
                std::cout << "---------------------------------------------------------------------------------------------------------------------------------\n";
            }
        }
        else
        {
            std::cout << RED << BOLD << "Incorrect password. Access denied.\n"
                      << RESET;
        }
    }
};
class SeatGenerator
{
public:
    SeatGenerator()
    {
        srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    }

    std::string generateRandomSeatNumber() const
    {
        char seatPrefix = 'A' + rand() % 4;
        int seatNumber = rand() % 100 + 1;
        std::ostringstream seatStream;
        seatStream << seatPrefix << seatNumber;
        return seatStream.str();
    }
};
int main()
{
    SeatGenerator sg; // Declare SeatGenerator
    std::cout << "Generated seat number: " << sg.generateRandomSeatNumber() << std::endl;

    std::string adminPassword = "admin";
    Train railwaySystem(adminPassword);

    int choice;
    while (true)
    {
        std::cout << CYAN << BOLD << "=======================================================================\n";
        std::cout << CYAN << BOLD << "========================== WELCOME TO RAILWAYS ===========================\n";
        std::cout << CYAN << BOLD << "=======================================================================\n"
                  << RESET;
        std::cout << GREEN << BOLD << "1. Passenger Panel\n";
        std::cout << GREEN << BOLD << "2. Admin Panel\n";
        std::cout << GREEN << BOLD << "3. Exit\n";
        std::cout << BLUE << BOLD << "Enter your choice: " << RESET;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            railwaySystem.passengerPanel();
            break;
        case 2:
            railwaySystem.adminPanel();
            break;
        case 3:
           std::cout << RED<<BOLD<<"Thank You For Visiting !"<<RESET;            
           return 0;
        default:
            std::cout << RED << BOLD << "Invalid choice! Please try again.\n"
                      << RESET;
            break;
        }
    }
}
