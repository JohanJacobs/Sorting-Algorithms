
#include <chrono>   // std::chrono::time_point, std::chrono::high_resolution_clock, std::chrono::milliseconds
#include <string>   // std::string
#include <iostream> // std::cout 
#include <iomanip>  // std::setw()
namespace JTime
{
    class Stopwatch
    {
     public:
         Stopwatch(const std::string& name, bool PrintResults = { false })
             :m_Name(name), m_Print{PrintResults}
        {
            m_Start = std::chrono::high_resolution_clock::now();
        }

         // returns time as microseconds 
         long long Elapsed() 
         {
			 std::chrono::time_point<std::chrono::high_resolution_clock> m_End = std::chrono::high_resolution_clock::now();
			 return std::chrono::duration_cast<std::chrono::microseconds>(m_End - m_Start).count();
         }

         long long ElapsedMillis() 
         {
             return Elapsed() / 1000;
         }

        ~Stopwatch()
        {
            if (m_Print)
            {
                auto elapsed = Elapsed();
                std::cout << "Timer " << m_Name << ": " << elapsed << " microseconds. (" << std::setw(3) << elapsed / 1000.0f <<" ms)\n";
            }
        }
     private:
        std::string m_Name;
        bool m_Print;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
    };
}