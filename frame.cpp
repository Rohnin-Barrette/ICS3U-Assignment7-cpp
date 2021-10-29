// Copyright (c) 2021 St. Mother Teresa HS All rights reserved.
//
// Created by: Rohnin Barrette
// Created on: oct 2021
// This program prints a sentence in a frame

#include <iostream>
#include <string>
#include <array>
#include <list>

std::string frame_builder(std::string user_sentence);

void frame_builder(std::string &user_sentence, std::list<std::string> &output) {
    // this function formats the string into a frame
    std::string user_list[0];
    std::list<std::string> padded_user_list;
    int largest_word_length = 0;
    std::string hr = "";
    std::string word;
    int loop_counter;
    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;
    int i;
    while ((pos = user_sentence.find(delimiter)) != std::string::npos) {
        token = user_sentence.substr(0, pos);
        padded_user_list.push_back(token);
        user_sentence.erase(0, pos + delimiter.length());
    }

    for (auto &word : padded_user_list) {
        if (largest_word_length == 0) {
            largest_word_length = word.length();
        } else if (word.length() > largest_word_length) {
            largest_word_length = word.length();
        } else {
            largest_word_length = word.length();
        }
    }

    for (i = 0; i <= largest_word_length + 4; i++) {
        hr.append("*");
    }

    output.push_back(hr);
    for (std::string word : padded_user_list) {
        std::string padded_word;
        while (word.length() <= largest_word_length) {
            word.append(" ");
        }

        padded_word.append("* ");
        padded_word.append(word);
        padded_word.append(" *");
        output.push_back(padded_word);
    }
    output.push_back(hr);
}

int main() {
    // this function gets input
    std::string user_sentence;
    std::list<std::string> frame;
    std::cout << "Enter your sentence: ";
    std::getline(std::cin, user_sentence);

    // padd the string with a space so that we can split on it above
    user_sentence.append(" ");

    try {
        frame_builder(user_sentence, frame);
        for (std::string word : frame) {
            std::cout << word << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "Invalid argument" << std::endl;
    }
    std::cout << "\nDone." <<std::endl;
}
