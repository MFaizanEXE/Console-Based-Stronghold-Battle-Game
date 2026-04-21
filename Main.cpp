#include "stronghold.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(10000, '\n');
}

int getValidChoice(int min, int max, const string& prompt) {
    int choice;
    while (true) {
        cout << prompt;
        if (cin >> choice && choice >= min && choice <= max) {
            clearInputBuffer();
            return choice;
        }
        cout << RED << "⚔️  Your choice is unworthy. Select a number between " << min << " and " << max << ".\n" << RESET;
        clearInputBuffer();
    }
}

void displayMenu() {
    cout << BOLD << "\n🛡️  === Stronghold Command Menu ===\n" << RESET;
    cout << "1. Lead Your Armies into Battle\n";
    cout << "2. Harden Your Soldiers\n";
    cout << "3. Elect a Ruler\n";
    cout << "4. Review Treasury and Finances\n";
    cout << "5. Acquire Vital Resources\n";
    cout << "6. Manage Diplomacy\n";
    cout << "7. Weave Shadows (Bribe or Blackmail)\n";
    cout << "8. Send a Royal Missive\n";
    cout << "9. Deceive with False Trade\n";
    cout << "10. Review Correspondence\n";
    cout << "11. Forge Greater Weapons\n";
    cout << "12. Craft Instruments of War\n";
    cout << "13. Engage in Espionage\n";
    cout << "14. Run the Smuggling Network\n";
    cout << "15. Tend to the Health of Your Realm\n";
    cout << "16. Expand and Fortify Structures\n";
    cout << "17. Chronicle Your Kingdom's Deeds\n";
    cout << "18. Unearth Past Records\n";
    cout << "19. Inscribe Your Legacy\n";
    cout << "20. Withdraw from the Throne\n";
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    cout << GREEN << "🏰 Welcome to Stronghold, where empires rise and fall!\n" << RESET;
    cout << "Player 1:\n";
    string kingdomName1 = getValidString("What shall your kingdom be called? ");
    string kingName1 = getValidString("By what name shall your sovereign be known? ");
    cout << "Player 2:\n";
    string kingdomName2 = getValidString("Name your rival kingdom (e.g., Ironhold): ");
    string kingName2 = getValidString("Name your rival sovereign: ");

    Kingdom player1(kingdomName1, kingName1);
    Kingdom player2(kingdomName2, kingName2);
    bool player1Turn = true;
    int turnCount = 1;

    while (true) {
        cout << BOLD << "\n⚔️  === Turn " << turnCount << " ===\n" << RESET;
        Kingdom& currentPlayer = player1Turn ? player1 : player2;
        Kingdom& otherPlayer = player1Turn ? player2 : player1;
        string playerLabel = player1Turn ? "Player 1" : "Player 2";

        cout << GREEN << playerLabel << "'s Command (" << currentPlayer.getName() << ")\n" << RESET;
        cout << YELLOW << "🗺️  Status of All Kingdoms:\n" << RESET;
        player1.printStatus();
        player2.printStatus();

        displayMenu();
        int choice = getValidChoice(1, 20, "What is your command, noble ruler (1-20)? ");

        try {
            switch (choice) {
            case 1: { //play turn
                currentPlayer.playTurn();
                break;
            }
            case 2: { // Train army
                int count = getValidChoice(1, 100, "How many warriors shall be trained (1-100)? ");
                currentPlayer.trainArmy(count);
                break;
            }
            case 3: { // Hold Election
                currentPlayer.holdElection();
                break;
            }
            case 4: { // Manage Loan or Audit
                std::cout << "1. Take Loan\n2. Repay Loan\n3. Audit Corruption\n";
                int subChoice = getValidChoice(1, 3, "Choose action (1-3): ");
                if (subChoice == 1 || subChoice == 2) {
                    int amount = getValidChoice(1, 10000, "Enter amount (1-10000): ");
                    currentPlayer.manageLoanOrAudit(subChoice, amount);
                }
                else {
                    currentPlayer.manageLoanOrAudit(subChoice, 0);
                }
                break;
            }
            case 5: { // Buy resources
                cout << "Available Resources: Food, Iron, Wood, Stone\n";
                string resource = getValidString("Name the resource you seek: ");
                int amount = getValidChoice(1, 1000, "How much do you wish to acquire (1-1000)? ");
                currentPlayer.buyResource(resource, amount);
                break;
            }

            case 6: { // Manage Diplomacy
                std::string targetKingdom = getValidString("Enter target kingdom (e.g., " + otherPlayer.getName() + "): ");
                std::cout << "1. Form Alliance\n2. Break Alliance\n3. Form Trade Agreement\n4. Establish Secure Route\n";
                int subChoice = getValidChoice(1, 4, "Choose action (1-4): ");
                currentPlayer.manageDiplomacy(targetKingdom, subChoice);
                break;
            }

            case 7: { // Bribe or Blackmail
                std::cout << "1. Bribe\n2. Blackmail\n";
                int subChoice = getValidChoice(1, 2, "Choose action (1-2): ");
                std::string candidate = getValidString("Enter candidate name: ");
                currentPlayer.bribeOrBlackmail(subChoice, candidate);
                break;
            }

            case 8: { // Send Message
                std::string recipient = getValidString("Enter recipient kingdom (e.g., " + otherPlayer.getName() + "): ");
                std::string message = getValidString("Enter message: ");
                currentPlayer.sendMessage(recipient, message);
                break;
            }

            case 9: { // Send Fake Trade Request
                std::string recipient = getValidString("Enter recipient kingdom (e.g., " + otherPlayer.getName() + "): ");
                currentPlayer.sendFakeTradeRequest(recipient);
                break;
            }

            case 10: // View Messages
                currentPlayer.viewMessages();
                break;

            case 11: // Upgrade Blacksmith
                currentPlayer.upgradeBlacksmith();
                break;

            case 12: { // Produce Weapons
                int count = getValidChoice(1, 50, "Enter number of weapons to produce (1-50): ");
                currentPlayer.produceWeapons(count);
                break;
            }

            case 13: { // Conduct Espionage
                std::cout << "1. Spy Mission\n2. Sabotage Weapons\n3. Steal Gold\n";
                int subChoice = getValidChoice(1, 3, "Choose espionage action (1-3): ");
                currentPlayer.conductEspionage(subChoice, otherPlayer);
                break;
            }

            case 14: { // Conduct Smuggling
                currentPlayer.conductSmuggling(otherPlayer);
                break;
            }

            case 15: { // Manage Healthcare
                std::cout << "1. Build Hospital\n2. Provide Services\n";
                int subChoice = getValidChoice(1, 2, "Choose healthcare action (1-2): ");
                currentPlayer.manageHealthcare(subChoice);
                break;
            }

            case 16: { // Manage Buildings
                std::cout << "1. Build Barracks\n";
                int subChoice = getValidChoice(1, 1, "Choose building action (1): ");
                currentPlayer.manageBuildings(subChoice);
                break;
            }

            case 17: { // Save Game State
                std::string filename = getValidString("Enter save file name: ");
                currentPlayer.saveState(filename);
                break;
            }

            case 18: { // Load Game State
                std::string filename = getValidString("Enter save file name: ");
                currentPlayer.loadState(filename);
                break;
            }

            case 19: // Save Score
                currentPlayer.saveScore();
                break;

       
            case 20:// exit
                cout << GREEN << "👑 Farewell, noble ruler! Your legacy shall be remembered.\n" << RESET;
                return 0;
            default:
                cout << RED << "⚔️  A misstep! Choose a valid command.\n" << RESET;
            }
        }
        catch (const InsufficientResourcesException& e) {
            std::cout << RED << "Error: " << e.what() << "\n" << RESET;
        }
        catch (const CorruptionException& e) {
            std::cout << RED << "Error: " << e.what() << "\n" << RESET;
        }
        catch (const exception& e) {
            cout << RED << "⚔️  An unexpected turn of fate: " << e.what() << "\n" << RESET;
        }


        player1Turn = !player1Turn;
        if (player1Turn) turnCount++;
    }

    system("pause");
}
