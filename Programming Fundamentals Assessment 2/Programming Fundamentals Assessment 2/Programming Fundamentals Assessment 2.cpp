#include <iostream>
#include <windows.h>
#include "Player.cpp"

using namespace std;

// Main menu variables
int menuInput = 0;

// Stat point variables
int unassignedStatPoints = 20;
int statPointInput = 0;
int strengthStatPoints = 0;
int speedStatPoints = 0;
int vitalityStatPoints = 0;
int defenceStatPoints = 0;

bool yesOrNoInput()
{
	if
	{
		cout << 
	}
}

void statPointAllocation()
{
	cout << "Allocate your stat points!" << endl;
	cout << "You can invest " << unassignedStatPoints << " stat points in:\n\n";
	cout << "- \033[33mStrength\033[0m" << endl;
	cout << "- \033[34mSpeed\033[0m" << endl;
	cout << "- \033[32mVitality\033[0m" << endl;
	cout << "- \033[35mDefence\033[0m\n\n";

	cout << "How many points would you like to allocate in \033[33mStrength\033[0m?\n\n";
	cout << "> ";
	cin >> statPointInput;
	strengthStatPoints = statPointInput;
	statPointInput = 0; // Resets statPointInput to allocate the next stat points

	cout << "How many points would you like to allocate in \033[34mSpeed\033[0m\n\n";
	cout << "> ";
	cin >> statPointInput;
	speedStatPoints = statPointInput;
	statPointInput = 0;

	cout << "How many points would you like to allocate in \033[32mVitality\033[0m\n\n";
	cout << "> ";
	cin >> statPointInput;
	vitalityStatPoints = statPointInput;
	statPointInput = 0;

	cout << "How many points would you like to allocate in \033[35mDefence\033[0m\n\n";
	cout << "> ";
	cin >> statPointInput;
	defenceStatPoints = statPointInput;
	statPointInput = 0;

	if (unassignedStatPoints <= 20)
	{
		cout << "You still have " << unassignedStatPoints << " unassigned stat points!" << endl;
		cout << "Continue? 
	}

}

void fight()
{

}

void shop()
{
	
}

void accessInventory()
{

}

void mainMenu()
{
	cout << "+-----------+" << endl;
	cout << "| \033[31mMain Menu\033[0m |" << endl; // Uses ANSI escape codes to colour text
	cout << "+-----------+\n\n";

	cout << "1. Fight!!!" << endl;
	cout << "2. Shop" << endl;
	cout << "3. Inventory" << endl;
	cout << "4. Exit\n\n";
	cout << "> ";

	cin >> menuInput;

	switch (menuInput)
	{
	case 1:
		fight();
	case 2:
		shop();
	case 3:
		accessInventory();
	case 4:
		cout << "Exiting game..." << endl;
		exit(1);
	}
}

int main()
{
	cout << "+---------------------+" << endl;
	cout << "| \033[31mMONSTER FIGHT ARENA\033[0m |" << endl;
	cout << "+---------------------+\n\n";

	cout << "Today is your first day as a professional monster fighter." << endl;
	cout << "Under the watch of thousands of people, fight to the death!!!\n\n";

	statPointAllocation();
	mainMenu();

	return 0;
}





//#include <iostream>
//
//using namespace std;
//
//void location_mainFoyer(int direction = 0)
//{
//    cout << "[LOCATION] Main Foyer\n\n";
//
//    cout << "Where do you want to go?\n\n1. NORTH\n2. EAST\n3. SOUTH\n4. WEST\n\n> "';
//    cin >> direction;
//
//    switch (direction)
//    {
//    case 1:
//        cout << "You go north" << endl;
//        break;
//    case 2:
//        cout << "You go east" << endl;
//        break;
//    case 3:
//        cout << "You go south" << endl;
//        break;
//    case 4:
//        cout << "You go west" << endl;
//        break;
//    }
//}
//
//int main()
//{
//    // Prologue
//    int storyDecision1 = 0;
//
//    cout << "Text-based Adventure Game" << endl;
//    cout << "-------------------------\n\n";
//
//    cout << "THURSDAY OCTOBER 31ST 2024" << endl;
//    cout << "11PM\n\n";
//
//    cout << "Through a mist of breath, you stare upwards at what your town is famous for: its haunted house." << endl;
//    cout << "There's no turning back now. You've wandered for hours, deep into the forest, camcorder and flashlight in your shivering hands." << endl;
//    cout << "There are too many mysteries hidden in this house that need to be unearthed. A group of friends went missing here 2 years ago," << endl;
//    cout << "but after the investigation team also went missing, no one has dared to investigate here since." << endl;
//    cout << "Today, that changes.\n\n";
//
//    cout << "You push open the main door with a loud creak, and take a step in. Immediately, you can smell stagnant, untouched air," << endl;
//    cout << "and somehow, the interior of this sealed building is colder than outside.\n\n";
//
//    cout << "1. Take a step forward\n2. Wait\n\n> ";
//    cin >> storyDecision1;
//
//    if (storyDecision1 == 1)
//    {
//        cout << "You take a step forward - and the door slams behind you!" << endl;
//        cout << "You try to pry it open, but no matter what, it won't open!" << endl;
//        cout << "[NEW OBJECTIVE] Escape!\n\n";
//
//        location_mainFoyer();
//    }
//   while (storyDecision1 == 2)
//    {
//        cout << "...\n\n";
//
//        cout << "1. Take a step forward\n2. Wait\n\n> ";
//        cin >> storyDecision1;
//    }
//
//}
//
//// General Plan:
//// Text-based adventure game based in a haunted house. You must try to escape by navigating the house, entering different rooms using compass directions.
//// You encounter different monsters and you must fight them in order to proceed. You lose if you die.
//// You can also find different weapons in different rooms to boost your character's damage.
//// Initially, your damage is based on stat points which the player can assign at the beginning.
//// Once you get the key to the main entrance, you can escape and win. (This will be in a random room in the second floor.) But you need to try and not die in the process.
//
//// Mechanics Plan:
//// Player 
//// ------
//// - Damage determined by player-assigned stat points and weapons found around the house
//
//// Navigation
//// ----------
//// - Player can travel through levels using North, East, South or West. Some directions are dead ends - if this is the case, then the direction should not be made available to
//// the player.
