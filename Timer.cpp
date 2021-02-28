#include "chrono"

class Timer
{
private:
    int *result;
    std::chrono::time_point<std::chrono::high_resolution_clock> timer;

public:
    Timer(int *res) : result(res)
    {
        timer = std::chrono::high_resolution_clock::now();
    };
    ~Timer()
    {
        Stop();
    };
    void Stop()
    {
        auto ended_at = std::chrono::high_resolution_clock::now();
        auto start_time = std::chrono::time_point_cast<std::chrono::nanoseconds>(timer).time_since_epoch().count();
        auto finish_time = std::chrono::time_point_cast<std::chrono::nanoseconds>(ended_at).time_since_epoch().count();
        *result = finish_time - start_time;
    }
};
