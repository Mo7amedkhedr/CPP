#include <fstream>
#include <iostream>
#include <string>


class Log_file{
    public:
        enum choices{
            INFO,
            WARN,
            ERROR
        };

        Log_file(const std::string& filename):filename(filename){}


        void log(choices level,const std::string& massage){
            std::ofstream file(filename,std::ios::app);
            if(file.is_open()){
                file<<loglevelstring(level)<<" : "<<massage<<std::endl;

            }
            file.close();
        }

        void dump(){
            std::ifstream file(filename);
            
            if(file.is_open()){
                std::string line;
                while (std::getline(file,line)) {
                    std::cout<<line<<std::endl;
                
                }
            }
            file.close();
        }
        void clear(){
            std::ofstream file(filename,std::ios::trunc);
            file.close();
        }
    private:
        std::string filename;
        
        std::string loglevelstring(choices level){
            switch (level) {
                case INFO:
                    return "INFO";
                case WARN:
                    return "WARN";
                case ERROR:
                    return "ERROR";
                default:
                    return "unknown";
            
            }
        }

};
int main(){
    Log_file log("file.txt");
    std::string userinput;
    std::cout<<" enter a message : ";
    std::getline(std::cin,userinput);

    if((userinput.find("warning" )) != std::string::npos){
        log.log(Log_file::WARN,userinput);
    } 
    else if(userinput.find("INFO")  != std::string::npos) {
      log.log(Log_file::INFO, userinput);
    }
    else {
        log.log(Log_file::ERROR, userinput);
        // log.clear();
    }
    log.dump();
   

    return 0;
}