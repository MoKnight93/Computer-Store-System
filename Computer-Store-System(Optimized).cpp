#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

// ============================ DATA ============================
struct Laptop
{
    string brand, name, color, cpu, gpu, os;
    int storageGB, cameraMP, ramGB, vramGB, price;
};

const int W = 62; // width of the console "window"

// ============================ UI HELPERS ============================
void line(char c = '-')
{
    cout << '+' << string(W - 2, c) << "+\n";
}

void center(const string &t)
{
    int space = W - 2 - (int)t.size();
    if (space < 0) space = 0;
    int left = space / 2;
    cout << '|' << string(left, ' ') << t << string(space - left, ' ') << "|\n";
}

void row(const string &text)
{
    string t = " " + text;
    int space = W - 2 - (int)t.size();
    if (space < 0) space = 0;
    cout << '|' << t << string(space, ' ') << "|\n";
}

void field(const string &label, const string &value)
{
    string l = label;
    while (l.size() < 10) l += ' ';
    row(l + ": " + value);
}

void header(const string &title)
{
    cout << "\n";
    line('=');
    center(title);
    line('=');
}

string toLower(string s)
{
    for (char &c : s) c = (char)tolower((unsigned char)c);
    return s;
}

string trim(const string &s)
{
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

string readLine(const string &prompt)
{
    cout << prompt;
    string s;
    if (!getline(cin, s))
    {
        cout << "\nInput closed. Goodbye!\n";
        exit(0);
    }
    return trim(s);
}

// Reads a whole number between lo and hi (keeps asking until valid)
int readInt(const string &prompt, int lo, int hi)
{
    while (true)
    {
        string s = readLine(prompt);
        bool ok = !s.empty() && s.size() < 9 &&
                  all_of(s.begin(), s.end(), [](char c) { return isdigit((unsigned char)c); });
        if (ok)
        {
            int v = stoi(s);
            if (v >= lo && v <= hi) return v;
        }
        cout << "  [!] Please enter a number from " << lo << " to " << hi << ".\n";
    }
}

void pause()
{
    readLine("\n  Press Enter to continue...");
}

string storageText(int gb)
{
    if (gb >= 1024) return to_string(gb / 1024) + " TB";
    return to_string(gb) + " GB";
}

// ============================ STORE ============================
class Store
{
protected:
    vector<Laptop> items;

public:
    Store()
    {
        items = {
            {"Lenovo", "Lenovo Legion 5", "Black", "Intel Core i7", "GTX 1660 Ti", "Windows 10", 1024, 18, 16, 6, 21000},
            {"Apple", "Apple MacBook Pro Late 2020", "Silver", "Apple M1", "Apple M1", "macOS", 512, 48, 8, 6, 25000},
            {"Dell", "Dell G5 15-5500", "Black", "Intel Core i5", "RTX 2060", "DOS", 512, 8, 16, 6, 18000},
            {"MSI", "MSI GF65", "Black", "Intel Core i9", "RTX 3060", "Windows 10", 2048, 18, 32, 8, 24000},
            {"HP", "HP OMEN 15", "Black", "Intel Core i7", "GTX 1660 Ti", "Windows 10", 1024, 18, 8, 4, 19500}};
    }

    void printCard(const Laptop &l, int number) const
    {
        line();
        center("[" + to_string(number) + "]  " + l.name);
        line();
        field("Brand", l.brand);
        field("Color", l.color);
        field("CPU", l.cpu);
        field("GPU", l.gpu);
        field("RAM", to_string(l.ramGB) + " GB");
        field("VRAM", to_string(l.vramGB) + " GB");
        field("Storage", storageText(l.storageGB));
        field("OS", l.os);
        field("Camera", to_string(l.cameraMP) + " MP");
        field("Price", to_string(l.price));
        line();
    }

    void showList(const vector<int> &idx) const
    {
        if (idx.empty())
        {
            cout << "\n  Sorry, we don't have any device matching that.\n";
            return;
        }
        cout << "\n  We have " << idx.size() << " device(s):\n";
        for (int i : idx) printCard(items[i], i + 1);
    }

    vector<int> allIndexes() const
    {
        vector<int> v;
        for (int i = 0; i < (int)items.size(); i++) v.push_back(i);
        return v;
    }

    // Lists the distinct values of one spec and lets the user pick one
    void searchBy(const string &title, function<string(const Laptop &)> key) const
    {
        vector<string> values;
        for (const Laptop &l : items)
        {
            string k = key(l);
            if (find(values.begin(), values.end(), k) == values.end()) values.push_back(k);
        }
        sort(values.begin(), values.end());

        header(title);
        for (int i = 0; i < (int)values.size(); i++)
            row("[" + to_string(i + 1) + "] " + values[i]);
        row("[0] Back");
        line();

        int c = readInt("  Your choice: ", 0, (int)values.size());
        if (c == 0) return;

        vector<int> res;
        for (int i = 0; i < (int)items.size(); i++)
            if (key(items[i]) == values[c - 1]) res.push_back(i);
        showList(res);
        pause();
    }

    void browseAll() const
    {
        header("ALL DEVICES");
        showList(allIndexes());
        pause();
    }

    void searchBrand() const
    {
        searchBy("SEARCH BY BRAND", [](const Laptop &l) { return l.brand; });
    }

    void searchTechnical() const
    {
        while (true)
        {
            header("SEARCH BY TECHNICAL DETAILS");
            row("[1] RAM");
            row("[2] VRAM");
            row("[3] Operating System");
            row("[4] Storage");
            row("[5] Camera");
            row("[0] Back");
            line();
            int c = readInt("  Your choice: ", 0, 5);
            if (c == 0) return;
            if (c == 1) searchBy("RAM", [](const Laptop &l) { return to_string(l.ramGB) + " GB"; });
            if (c == 2) searchBy("VRAM", [](const Laptop &l) { return to_string(l.vramGB) + " GB"; });
            if (c == 3) searchBy("OPERATING SYSTEM", [](const Laptop &l) { return l.os; });
            if (c == 4) searchBy("STORAGE", [](const Laptop &l) { return storageText(l.storageGB); });
            if (c == 5) searchBy("CAMERA", [](const Laptop &l) { return to_string(l.cameraMP) + " MP"; });
        }
    }
};

// ============================ CUSTOMER ============================
class User : public Store
{
private:
    string name, email, phone;

    bool validPhone(const string &p) const
    {
        int digits = 0;
        for (size_t i = 0; i < p.size(); i++)
        {
            if (isdigit((unsigned char)p[i])) digits++;
            else if (!(i == 0 && p[i] == '+')) return false;
        }
        return digits >= 8 && digits <= 15;
    }

    bool validEmail(const string &e) const
    {
        size_t at = e.find('@');
        if (at == string::npos || at == 0) return false;
        size_t dot = e.find('.', at);
        return dot != string::npos && dot > at + 1 && dot + 1 < e.size() && e.find(' ') == string::npos;
    }

    void askPersonalInfo()
    {
        header("YOUR INFORMATION");
        do { name = readLine("  Your name  : "); } while (name.empty() && (cout << "  [!] Name can't be empty.\n"));
        while (true)
        {
            phone = readLine("  Your phone : ");
            if (validPhone(phone)) break;
            cout << "  [!] Enter a valid phone number (8-15 digits).\n";
        }
        while (true)
        {
            email = readLine("  Your email : ");
            if (validEmail(email)) break;
            cout << "  [!] Enter a valid email (example: name@mail.com).\n";
        }
    }

    void receipt(const Laptop &l, const string &payment)
    {
        srand((unsigned)time(0));
        int orderNo = 100000 + rand() % 900000;

        header("RECEIPT");
        field("Order No", "#" + to_string(orderNo));
        field("Name", name);
        field("Phone", phone);
        field("Email", email);
        field("Payment", payment);
        line();
        center("PRODUCT");
        line();
        field("Product", l.name);
        field("Brand", l.brand);
        field("Color", l.color);
        field("CPU", l.cpu);
        field("GPU", l.gpu);
        field("RAM", to_string(l.ramGB) + " GB");
        field("VRAM", to_string(l.vramGB) + " GB");
        field("Storage", storageText(l.storageGB));
        field("OS", l.os);
        field("Camera", to_string(l.cameraMP) + " MP");
        line();
        field("TOTAL", to_string(l.price));
        line('=');
        center("Successful purchase - Thank you!");
        line('=');
    }

public:
    void buy()
    {
        header("MAKE YOUR DECISION");
        showList(allIndexes());
        int choice = readInt("  Enter device number (0 = cancel): ", 0, (int)items.size());
        if (choice == 0) return;

        // Confirm / modify the order
        while (true)
        {
            header("YOUR ORDER");
            printCard(items[choice - 1], choice);
            row("[1] Confirm order");
            row("[2] Modify (choose another device)");
            row("[0] Cancel");
            line();
            int c = readInt("  Your choice: ", 0, 2);
            if (c == 0) return;
            if (c == 1) break;
            showList(allIndexes());
            choice = readInt("  Enter new device number (0 = cancel): ", 0, (int)items.size());
            if (choice == 0) return;
        }

        header("PAYMENT METHOD");
        row("[1] Cash");
        row("[2] Credit");
        line();
        int p = readInt("  Your choice: ", 1, 2);
        string payment = (p == 1) ? "Cash" : "Credit";

        askPersonalInfo();
        receipt(items[choice - 1], payment);
        pause();
    }
};

// ============================ MAIN ============================
int main()
{
    User store;

    while (true)
    {
        header("WELCOME TO COMP_STORE");
        center("Thank you for choosing our store");
        line();
        row("What are you looking for?");
        row("");
        row("[1] Browse all devices");
        row("[2] Search by Brand");
        row("[3] Search by Technical Details");
        row("[4] Buy a device");
        row("[0] Exit");
        line();

        int c = readInt("  Your choice: ", 0, 4);
        if (c == 0) break;
        if (c == 1) store.browseAll();
        else if (c == 2) store.searchBrand();
        else if (c == 3) store.searchTechnical();
        else if (c == 4) store.buy();
    }

    cout << "\n  Goodbye, see you soon!\n";
    return 0;
}