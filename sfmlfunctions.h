//#include <iostream>
//#include <fstream>
//#include<string>
//#include<cstring>
//#include <SFML/Graphics.hpp>
//using namespace std;
//using namespace sf;
//void displayText(const string& text, Font& font, RenderWindow& window) {
//    // Set up text
//    Text message;
//    message.setFont(font);
//    message.setString(text);
//    message.setCharacterSize(24);
//    message.setPosition(10, 10);
//    message.setFillColor(Color::Green);
//    window.clear(Color::Blue);
//    window.draw(message);
//    window.display();
//    sleep(seconds(0.5));
//}
//int keypressed(RenderWindow& window, Font& font)
//{
//    while (true) {
//        Event event;
//        window.pollEvent(event);
//        if (event.type == Event::Closed) {
//            window.close();
//        }
//
//        if (event.type == Event::TextEntered) {
//            if (event.text.unicode >= '0' && event.text.unicode <= '9') {
//                int enteredNumber = event.text.unicode - '0';
//                return enteredNumber;
//            }
//        }
//    }
//}
//string getstring(RenderWindow& window, Font& font) {
//    string inputString;
//    Text inputText("", font, 24);
//    inputText.setFillColor(Color::Green);
//    inputText.setPosition(10, 10);
//    while (true) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed) {
//                window.close();
//            }
//            else if (event.type == Event::TextEntered) {
//                if (event.text.unicode == 13) { // Enter key
//                    return inputString;
//                }
//                else if (event.text.unicode == 8 && !inputString.empty()) { // Backspace key
//                    inputString.pop_back();
//                }
//                else if (event.text.unicode < 128) {
//                    char enteredChar = static_cast<char>(event.text.unicode);
//                    inputString += enteredChar;
//                }
//                // Update the displayed text
//                inputText.setString(inputString);
//                window.clear(Color::Blue);
//                window.draw(inputText);
//                window.display();
//            }
//        }
//    }
//}