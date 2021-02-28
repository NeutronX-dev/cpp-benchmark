# cpp-benchmark
## File Tree
```
.
├── cpp-benchmark/
│   └── Timer.cpp
└── main.cpp
```
If you want to change the directory just make sure you update the path. In this example `main.cpp` is the main project. and [`Timer.cpp`](https://github.com/NeutronX-dev/cpp-benchmark/blob/main/Timer.cpp) is the source code.

## Example
#### (In `main.cpp`)
```cpp
{
    #include "cpp-benchmark/Timer.cpp"

    int main()
    {
        int nanoseconds; // Result will be stored Here
        {
            std::vector<int*> intReferences;
            Timer myTimer(&nanoseconds); // Starts the Timer (Stack Allocated)
            for (size_t i = 0; i < 10000; i++)
            {
                intReferences.push_back(new int(i)); // Pushes a Reference to Vector
            }
            std::cout << "Made 10,000 References" << std::endl;
        }
        // Prints nanoseconds and miliseconds. (nanoseconds/1000000)
        std::cout << "In " << nanoseconds << " nanoseconds! (" << nanoseconds/1e+6 << " miliseconds)" << std::endl;
    }

    /*
        As soon as the destructor gets called
        the timer stops, and the result is
        saved into *nanoseconds.
    */
}
```

# Disclaimer
### This script is not originally made by me. It was made by Cherno in his video named "[BENCHMARKING in C++](https://www.youtube.com/watch?v=YG4jexlSAjc)".
