#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector <std::string> split_line (std::string line) {
  std::vector <std::string> line_split;
  std::stringstream ss (line);
  std::string phrase;
  while (std::getline (ss, phrase, ',')) {
    phrase.erase (0, phrase.find_first_not_of (" \t\n\r"));
    phrase.erase (phrase.find_last_not_of (" \t\n\r") + 1);
    line_split.push_back (phrase);
  }
  return line_split;
}

int main () { 

  std::string d;
  std::cout << "What director do you like? ";
  std::getline (std::cin, d);
  std::string g;
  std::cout << "What genre do you like? ";
  std::getline (std::cin, g);
  std::string r;
  std::cout << "What rating do you like? ";
  std::getline (std::cin, r);

  std::ifstream reader;
  reader.open ("movies.txt");
  std::vector <std::string> movie_names;
  std::vector <std::string> directors;
  std::vector <std::string> genres;
  std::vector <std::string> age_ratings;

  std::string reader1;
  while(getline (reader, reader1)) {
    std::vector <std::string> line = split_line (reader1);

    movie_names.push_back (line[0]);
    directors.push_back (line[1]);
    genres.push_back (line[2]);
    age_ratings.push_back (line[3]);
  }

  while(true){
    int q1;
    std::cout << "\n1. Recommendations by director\n2. Recommendations by genre\n3. Recommendations by age rating\n4. Recommendations by director and genre\n5. Recommendations by director and age rating\n6. Recommendations by genre and age rating\n7. Recommendations by director, genre, and age rating\n8.Exit\n\n";
    std::cin >> q1;
      
    if(q1 == 1){  
      std::cout << "\n\nHere are the movies:\n";
      for(int i = 0; i < movie_names.size(); i++) {
        std::string current = directors[i];
        if(current == d){
          std::string movie = movie_names[i];
          std::cout << movie << "\n";
        }
      }
    }
    
    if(q1 == 2){
      std::cout << "\n\nHere are the movies:\n";
      for(int i = 0; i < movie_names.size(); i++){
        std::string current = genres[i];
        if(current == g){
          std::string movie = movie_names[i];
          std::cout << movie << "\n";
        }
      }
    }
    
    if(q1 == 3){
      std::cout << "\n\nHere are the movies:\n";
      for(int i = 0; i < movie_names.size(); i++){
        std::string current = age_ratings[i];
        if(current == r){
          std::string movie = movie_names[i];
          std::cout << movie << "\n";
        }
      }
    }
    
    if(q1 == 4){
      std::cout << "\n\nHere are the movies:\n";
      for(int i = 0; i < movie_names.size(); i++){
        std::string current1 = directors [i];
        std::string current2 = genres [i];
        if(current1 == d && current2 == g){
          std::string movie = movie_names [i];
          std::cout << movie << "\n";
        }
      }    
    }
  
    if(q1 == 5){
      std::cout << "\n\nHere are the movies:\n";
      for(int i = 0; i < movie_names.size(); i++){
        std::string current1 = directors [i];
        std::string current2 = age_ratings [i];
        if(current1 == d && current2 == r){
          std::string movie = movie_names [i];
          std::cout << movie << "\n";
        }
      }    
    }
    
    if(q1 == 6){
      std::cout << "\n\nHere are the movies:\n";
      for(int i = 0; i < movie_names.size(); i++){
        std::string current1 = genres [i];
        std::string current2 = age_ratings [i];
        if(current1 == g && current2 == r){
          std::string movie = movie_names [i];
          std::cout << movie << "\n";
        }
      }    
    }
    
    if(q1 == 7){
      std::cout << "\n\nHere are the movies:\n";
      for(int i = 0; i < movie_names.size(); i++){
        std::string current1 = directors [i];
        std::string current2 = age_ratings [i];
        std::string current3 = genres [i];
        if(current1 == d && current2 == r && current3 == g){
          std::string movie = movie_names [i];
          std::cout << movie << "\n";
        }
      }    
    }
    
    if(q1 == 8){
      std::cout << "\n\nBye\n";
      break;
    }
  }
}
