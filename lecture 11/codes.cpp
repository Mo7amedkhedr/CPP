
#include <chrono>
#include <iostream>
#include <iterator>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>

enum class TrafficLight{
    RED,
    YELLOW,
    GREEN
};
enum class triggerTrafficLight{
 gotoRed,
 gotoYellow,
 gotoGreen
};
bool redHandler()
{
    std::cout<<"Red Handler"<<std::endl;
    return true;
}
bool yellowHandler(){
    std::cout<<"Yellow Handler"<<std::endl;
    return true;
}
bool greenHandler(){
    std::cout<<"Green Handler"<<std::endl;
    return true;
}

class Istate{
    public:
    virtual void handler()=0;
    virtual ~Istate()=default;
};
class RedState:public Istate{
    void handler() override{
        std::cout<<"I'm in Red State"<<std::endl;
    }
};
class YellowState:public Istate{
    void handler() override{
        std::cout<<"I'm in Yellow State"<<std::endl;
    }
};
class GreenState:public Istate{
    void handler() override{
        std::cout<<"I'm in Green State"<<std::endl;
    }
};
int main(){
    std::vector<int>n={1,2,3,5,1,2,8,3,100};
    std::vector<int>n2={1,2,13,5,1,2,8,3,100};
    std::vector<int>n3={22,33,3,4};
    std::vector<int>sub_n3 ={5,1,2};
    std::cout<<std::all_of(n.begin(),n.end(),[](int i){return i>10;})<<std::endl;
    std::cout<<std::any_of(n.begin(), n.end(), [](int i){return i>10;})<<std::endl;
    std::cout<<std::none_of(n.begin(), n.end(), [](int i){return i>10;})<<std::endl;
    std::for_each(std::begin(n),std::end(n),[](int i){std::cout<<i<<" ";});
    std::cout<<std::endl;
    std::cout<<std::count(n.begin(),n.end(),3)<<std::endl;
    std::cout<<std::count_if(n.begin(),n.end(),[](int x){return x>10;})<<std::endl;
    auto p = std::mismatch(n.begin(),n.end(),n2.begin(),n.end());
    std::cout<<"First unequal elements: "<<*p.first <<" and "<<*p.second <<std::endl;
    auto it = std::find(n.begin(),n.end(),3);
    if(it!= n.end()){
        std::cout<<"Found 3 at position: "<<std::distance(n.begin(), it)<<std::endl;
    }else{
        std::cout<<"3 not found in the vector"<<std::endl;
    }
    auto it2 = std::find_if(n.begin(),n.end(),[](int x){return x>3;});
    if(it2!= n.end()){
        std::cout<<"Found at:  "<<std::distance(n.begin(), it2)<<std::endl; 
    }else{
        std::cout<<"not found "<<std::endl;
    }
    std::cout<<*std::find_first_of(n.begin(),n.end(),n3.begin(),n3.end())<<std::endl;;
  
    auto  search_ressss =   std::search(n.begin(),n.end(),sub_n3.begin(),sub_n3.end());
    if(search_ressss!= n.end()){
        std::cout<<"Found subvector at position: "<<std::distance(n.begin(), search_ressss)<<std::endl;
    }else{
        std::cout<<"subvector not found in the vector"<<std::endl;
    }

   std::transform(n.begin(),n.end(),n.begin(),[](int x){return x+1;});
    for(int i:n){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::sort(n.begin(),n.end(),[](int a, int b){return a>b;});
    for(int i:n){  
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::vector<int> v = {1,2,3,4,5};
    std::vector<int> v2 = {1,33,2,3,4,5,6};
    std::vector<int> result;
    std::set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), std::back_inserter(result));
    std::cout<<"set intersection: ";
    for(int i:result){
        
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::vector<int> result2;
    std::set_union(v.begin(), v.end(), v2.begin(), v2.end(), std::back_inserter(result2));
       std::cout<<"set union: ";
    for(int i:result2){
        
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::vector<int> result3;
    std::set_difference(v.begin(), v.end(), v2.begin(), v2.end(), std::back_inserter(result3));
    std::cout<<"set difference: ";
    for(int i:result3){
           
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    
    
    







    /*std::map<TrafficLight, std::pair<TrafficLight,  Istate*>> stateMachine ={
        {TrafficLight::RED, {TrafficLight::YELLOW, new YellowState}},
        {TrafficLight::YELLOW, {TrafficLight::GREEN, new GreenState}},
        {TrafficLight::GREEN, {TrafficLight::RED, new RedState}}
    };
    TrafficLight currentState = TrafficLight::RED;
  
    int cnt=0;
    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"Current state: "<<static_cast<int>(currentState)<<std::endl;
        stateMachine[currentState].second->handler();
        currentState = stateMachine[currentState].first;
        if(++cnt ==3){
            break;
        }
    }
*/







 // in multimap must check because no indexing you can use it by making loop
 /**std::multimap<std::string, std::string>db2{
    {"name","khedr"},
    {"age","22"},
    {"city","mansoura"},
    {"country","Egypt"},
    {"name","mohamed"},
    {"age","23"},
    {"city","cairo"},
    {"country","Egypt"}
  };
  for(auto i :db2)
  {
    std::cout<<i.first<<" : "<<i.second<<std::endl;
  }

  auto range = db2.equal_range("name");
  for(auto it = range.first; it!= range.second; ++it)
    std::cout<<it->first<<" : "<<it->second<<std::endl;
  // count how many entries with "name" as "mohamed"
  std::cout<<"count: "<<std::distance(range.first, range.second)<<std::endl;
 */
 /*std::unordered_map<std::string, std::vector<std::string>> shopping
 {
    {"apple", {"red", "green", "yellow"}},
    {"banana", {"yellow", "yellow", "yellow"}},
    {"orange", {"orange", "orange", "orange"}}
  };
  for(auto i : shopping)
  {
    std::cout<<i.first<<" : ";
    for(auto &fruit : i.second)
      std::cout<<fruit<<" ";
    std::cout<<std::endl;
  }*/
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  /*
  //map , multimap ====> tree
  // unordered map ====> hash table
  std::map<std::string , std::string>db{
    {"name","khedr"},
    {"age","22"},
    {"city","mansoura"},
    {"country","Egypt"}
  };
  db.insert(std::make_pair("email", "mohamed@gmail.com"));
  db.insert(std::make_pair("phone", "0123456789"));*/
  /*std::cout<<"nmae : "<<db["name"]<<std::endl;
  std::cout<<"email : "<<db["email"]<<std::endl;
  std::cout<<"phone : "<<db["phone"]<<std::endl;*/
  /*std::cout<<"------------------------------------------"<<std::endl;
  for(auto &item : db)
    std::cout<<item.first<<" : "<<item.second<<std::endl;
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<"size: "<<db.size()<<std::endl;
  db["age"]="23";
  std::cout<<db.empty()<<std::endl;
  auto it =db.find("phone");
  if(it!=db.end()){
    std::cout<<"found : "<<it->first<<" : "<<it->second<<std::endl;
  }
  else{
    std::cout<<"not found"<<std::endl;
  }*/


}