#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Expression Statement
    std::cout << "You are a secret agent breaking into a level " << Difficulty;
    std::cout << "\nsecure server room... \nYou need to enter the correct order to continue.." << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    // Declaration Statement
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    // Expression Statement
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;
    
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB* GuessC;
    
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You Win!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "You Lose!" << std::endl;
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    
    while(LevelDifficulty <= MaxDifficulty) // Loop the game until win
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any error
        std::cin.ignore(); // Discards the buffer
        
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "\n*** Great work agent! You got all of the files! Now get out of there! ***\n";
    
    return 0;
}
