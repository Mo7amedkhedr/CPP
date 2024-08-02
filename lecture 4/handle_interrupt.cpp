#include <cstdlib>
#include <iostream>
#include <csignal> 


void sigint_handler(int signum) { 
    std::cout << "Ctrl+C detectedn  (" << signum << ") recevied "<< std::endl;
    exit(signum);
  }

 int main()
 {
  signal(SIGINT, sigint_handler); //SIGINT -> Receipt of an interactive attention signal.

     while(1) {
      std::cout << "Hi Mohamed Khedr ... " << std::endl;
     sleep(2);
   }

   return 0;


 } 