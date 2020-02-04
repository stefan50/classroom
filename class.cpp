#include <iostream>
#include <cstring>

using namespace std;

class Dog {
	double height_;
	double width_;
	bool is_alive_;
	double age_;
	char collar_colour_[50];
public:
	Dog(double height, double width, char collar_colour[50], double age) {
		height_ = height;
		width_ = width;
		strcpy(collar_colour_, collar_colour);
		age_ = age;
		is_alive_ = true;
	}

	double get_height() {
		return height_;
	}

	double get_width() {
		return width_;
	}

	char* get_colour() {
		return collar_colour_;
	}

	bool is_alive() {
		return is_alive_;
	}

	double get_age() {
		return age_;
	}

	void set_height(double height) {
		height_ = height;
	}

	void kill() {
		is_alive_ = false;
		cout << "Your dog is dead!" << endl;
	}

	void feed(int ammount) {
		age_ += ((ammount/2) + (ammount/3));
	        if (age_ >= 10) {
			kill();
		}	
	}

	void feed(Dog dog) {
		age_ -= (dog.get_age()/2);
		cout << "You just sacrificed a dog! Shame on you!!!" << endl;
	}
};

int main() {
	char tupo[50];
	char food[50];
	cin >> tupo;
	Dog lilly(2,3,tupo,5);
	while(lilly.is_alive()) {
		cout << "Please, feed your dog: ";
		cin >> food;
		if(!strcmp(food, "dog")) {
			Dog dog(2,3,tupo,5);
			lilly.feed(dog);
		}
		else {
			int foodd = atoi(food);
		        lilly.feed(foodd);	
		}	
	}
	return 0;
}
