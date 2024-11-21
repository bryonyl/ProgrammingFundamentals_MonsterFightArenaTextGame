#include <iostream>
#include <windows.h>
#include "Player.cpp"

// Main menu variables
int menuInput = 0;

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
	std::cout << "+-----------+" << std::endl;
	std::cout << "| \033[31mMain Menu\033[0m |" << std::endl; // Uses ANSI escape codes to colour text
	std::cout << "+-----------+\n\n";

	std::cout << "1. Fight!!!" << std::endl;
	std::cout << "2. Shop" << std::endl;
	std::cout << "3. Inventory" << std::endl;
	std::cout << "4. Exit\n\n";
	std::cout << "> ";

	std::cin >> menuInput;

	switch (menuInput)
	{
	case 1:
		fight();
	case 2:
		shop();
	case 3:
		accessInventory();
	case 4:
		std::cout << "Exiting game..." << std::endl;
		exit(1);
	}
}

int main()
{
	std::cout << "+---------------------+" << std::endl;
	std::cout << "| \033[31mMONSTER FIGHT ARENA\033[0m |" << std::endl;
	std::cout << "+---------------------+\n\n";

	std::cout << "Today is your first day as a professional monster fighter." << std::endl;
	std::cout << "Under the watch of thousands of people, fight to the death!!!\n\n";

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
//    std::cout << "[LOCATION] Main Foyer\n\n";
//
//    std::cout << "Where do you want to go?\n\n1. NORTH\n2. EAST\n3. SOUTH\n4. WEST\n\n> "';
//    std::cin >> direction;
//
//    switch (direction)
//    {
//    case 1:
//        std::cout << "You go north" << std::endl;
//        break;
//    case 2:
//        std::cout << "You go east" << std::endl;
//        break;
//    case 3:
//        std::cout << "You go south" << std::endl;
//        break;
//    case 4:
//        std::cout << "You go west" << std::endl;
//        break;
//    }
//}
//
//int main()
//{
//    // Prologue
//    int storyDecision1 = 0;
//
//    std::cout << "Text-based Adventure Game" << std::endl;
//    std::cout << "-------------------------\n\n";
//
//    std::cout << "THURSDAY OCTOBER 31ST 2024" << std::endl;
//    std::cout << "11PM\n\n";
//
//    std::cout << "Through a mist of breath, you stare upwards at what your town is famous for: its haunted house." << std::endl;
//    std::cout << "There's no turning back now. You've wandered for hours, deep into the forest, camcorder and flashlight in your shivering hands." << std::endl;
//    std::cout << "There are too many mysteries hidden in this house that need to be unearthed. A group of friends went missing here 2 years ago," << std::endl;
//    std::cout << "but after the investigation team also went missing, no one has dared to investigate here since." << std::endl;
//    std::cout << "Today, that changes.\n\n";
//
//    std::cout << "You push open the main door with a loud creak, and take a step in. Immediately, you can smell stagnant, untouched air," << std::endl;
//    std::cout << "and somehow, the interior of this sealed building is colder than outside.\n\n";
//
//    std::cout << "1. Take a step forward\n2. Wait\n\n> ";
//    std::cin >> storyDecision1;
//
//    if (storyDecision1 == 1)
//    {
//        std::cout << "You take a step forward - and the door slams behind you!" << std::endl;
//        std::cout << "You try to pry it open, but no matter what, it won't open!" << std::endl;
//        std::cout << "[NEW OBJECTIVE] Escape!\n\n";
//
//        location_mainFoyer();
//    }
//   while (storyDecision1 == 2)
//    {
//        std::cout << "...\n\n";
//
//        std::cout << "1. Take a step forward\n2. Wait\n\n> ";
//        std::cin >> storyDecision1;
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
