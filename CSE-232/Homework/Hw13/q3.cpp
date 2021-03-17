#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::find;
#include <numeric>
using std::accumulate;
#include <iostream>

vector<string> unique_pokemon(vector<string>& old_pokedex,
                              const string& found_pokemon){
    for(auto ptr = old_pokedex.begin(); ptr != old_pokedex.end(); ++ptr){
        if (found_pokemon == *ptr){
            return old_pokedex;
        } 
    }
    
    old_pokedex.push_back(found_pokemon);
    return old_pokedex;
    
} // fn 



int main(){

    
    vector<string> pokemon_seen = {"Vulpix", "Dratini", "Squirtle", 
                                "Seel", "Growlithe", "Dratini",
                                "Rapidash", "Vulpix", "Scyther"};
    vector<string> expected = {"Vulpix", "Dratini", "Squirtle", 
                            "Seel", "Growlithe", "Rapidash", "Scyther"};
    vector<string> result = accumulate(pokemon_seen.begin(), 
                                    pokemon_seen.end(),
                                    vector<string>(),
                                    unique_pokemon);
    assert(expected == result);

} // main