// brainfuck == bf == boyfriend 

#include <iostream> 
#include <cstdint> 
#include <cstdlib> 


int bf(bool liv, std::string input, short index = 0, bool inner=0) { 
    uint8_t arr[30000]; 
    while (1) { 
        if (liv == 0) { std::cout << "Input: "; }  
        std::cin >> input; 
        std::cout << "\n"; 
        if (input==">") {  
            ++index;
        } 
        else if (input== "<") {  
            --index;
        }
        else if (input== "+") {  
            arr[index]++; 
        } 
        else if (input=="-") { 
            arr[index]--; 
        }
        else if (input==".") {  
            std::cout << arr[index]; 
        } 
        else if (input==",") {          
            std::string n2; 
            std::cout << "Input At " << index << ": "; 
            std::cin >> n2; 
            arr[index] = (uint8_t) std::stoi(n2); 
        } 
        else if (input=="[") {  
            std::string nin; 
            std::cout << "Inner Input: "; 
            std::cin >> nin; 
            while (nin != "]") { 
                if (liv==1) { bf(-1, nin, index=index); break; } 
                bf(liv, input, index=index, inner=1);
                std::string rin;
                std::cout<<"\n Inner Input: "; 
                std::cin>>rin;nin=rin; 
            } 
        } 
        std::cout << "\n"; 
    } 
    return 0; 
} 


int main(int argc, char *argv[]) { 
    std::cout << "Beginning Boyfriend Brainfuck \n"; 
    if (argc>1) { bf(1, ""); return 0; } 
    bf(0, ""); 
    return 0; 
} 

// liv=0 == NON LIVE 
// liv=1 == LIVE 
// liv=-1 == LIVE INNER SCOPE 
