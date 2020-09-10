Magic Spells
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

/* Enter your code here. Read input from STDIN. Print output to STDOUT */

    /*Spell &a = dynamic_cast<Spell>(Fireball);
    Spell &b = dynamic_cast<Frostbite>(spell);
    Spell &c = dynamic_cast<Waterbolt>(spell);
    Spell &d = dynamic_cast<Thunderstorm>(spell);*/

    Fireball *a = dynamic_cast<Fireball*>(spell);
    Frostbite *b = dynamic_cast<Frostbite*>(spell);
    Waterbolt *c = dynamic_cast<Waterbolt*>(spell);
    Thunderstorm *d = dynamic_cast<Thunderstorm*>(spell);

    if (a != NULL){
        a->revealFirepower();
    }
    else if (b != NULL){
        b->revealFrostpower();
    }
    else if(c != NULL){
        c->revealWaterpower();
    }
    else if (d != NULL){
        d->revealThunderpower();
    }
    else{
        string  str = spell->revealScrollName();
        string str2 = SpellJournal::read();

        int m = str.size();
        int n = str2.size();

        vector<vector<int>> s(m + 1, vector<int>(n + 1, 0));

        for (int i = 0 ; i < m; ++i){
            for (int j = 0; j < n; ++j){
                s[i+1][j+1] = max(s[i][j] + (str[i] == str2[j]), max(s[i+1][j], s[i][j+1]));
            }
        }
        cout << s[m][n] << endl;
    }
        
 
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
