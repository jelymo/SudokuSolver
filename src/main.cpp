#include <iostream>
#include <chrono>
#include <thread>

class SudokuProblem
{
private:
    uint8_t data[81] = {};

public:
    const uint8_t const get(const int &x, const int &y)
    {
        return data[x + (y * 9)];
    }

    void set(const int &x, const int &y, uint8_t n)
    {
        data[x + (y * 9)] = n;
    }

    bool isCoodinateValid(const int &x, const int &y, const uint8_t &n)
    {
        if (n > 9 || n < 0)
        {
            return false;
        }
        return true;
    }

    void solve()
    {
        for (int y = 0; y < 9; y++)
        {
            for (int x = 0; x < 9; x++)
            {
                uint8_t value = get(x, y);
                if (value == 0)
                {
                    for (int n = 1; n <= 9; n++)
                    {
                        if (isValid(x, y, n))
                        {
                            // system("cls");
                            // std::cout << "Solving..." << std::endl;
                            // print();
                            // std::this_thread::sleep_for(std::chrono::milliseconds(1));
                            set(x, y, n);
                            solve();
                            if(!isFinished())
                            {
                                set(x, y, 0);
                            }
                        }
                    }
                    return;
                }
            }
        }
        
    }

    bool isFinished()
    {
        for (int i = 0; i < 81; i++)
        {
            if(data[i] == 0 )
            {
                return false;
            }
        }
        return true;
    }
    

    bool isValid(const int &x, const int &y, const uint8_t &n)
    {
        for (int yi = 0; yi < 9; yi++)
        {
            if (get(x, yi) == n)
            {
                return false;
            }
        }

        for (int xi = 0; xi < 9; xi++)
        {
            if (get(xi, y) == n)
            {
                return false;
            }
        }

        int startingIndex = ((x / 3) * 3) + ((y / 3) * 27);
        for (int i = 0; i < 9; i++)
        {
            int index = startingIndex + ((i / 3) * 9) + (i % 3);
            if (data[index] == n)
            {
                return false;
            }
        }

        return true;
    }

    void print()
    {
        for (int y = 0; y < 9; y++)
        {
            for (int x = 0; x < 9; x++)
            {
                std::cout << (int)get(x, y) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    std::cout << "Sudoku Solver" << std::endl;
    SudokuProblem problem;

    // 5 3 0 0 7 0 0 0 0 
    // 6 0 0 1 9 5 0 0 0 
    // 0 9 8 0 0 0 0 6 0 
    // 8 0 0 0 6 0 0 0 3 
    // 4 0 0 8 0 3 0 0 1 
    // 7 0 0 0 2 0 0 0 6 
    // 0 6 0 0 0 0 2 8 0 
    // 0 0 0 4 1 9 0 0 5 
    // 0 0 0 0 8 0 0 7 9 


    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            int n;
            std::cin >> n;
            if (problem.isCoodinateValid(x, y, n))
            {
                problem.set(x, y, n);
            }
            else
            {
                std::cout << "Invalid Number At: (" << x << "," << y << ") with value: " << n << std::endl;
                system("pause");
                return -1;
            }
        }
    }

    problem.solve();

    std::cout << "\nSolution:" << std::endl;
    std::cout << "================" << std::endl;
    problem.print();
    std::cout << std::endl;
    system("pause");
    return 0;
}
