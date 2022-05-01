#include "PokerGame.h"

PokerGame::PokerGame() {
	//TO_DO: initial constructor
}

void PokerGame::distribute(bool (&usedCards)[52]) {
	//TO_DO: Random generate five cards to player
	//Hint: Use usedCards to record which card have been distributed
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		int num = rand() % 52;
		if (usedCards[num]) i--;
		else {
			usedCards[num] = true;
			this->playerCards.push_back(num);
		}
	}
}

void PokerGame::set(vector<int> cards) {
	//TO_DO: Set the cards to player
	for (int i = 0; i < 5; i++) {
		this->playerCards.push_back(cards[i]);
	}
}

void PokerGame::printCards() {
	cout << "Player cards:" << endl;
	for (int i = 0; i < 5; i++) {
		//TO_DO: Print the player's cards.
		// For example: "C1" "S2" "H3" ...
		int num = this->playerCards[i];
		int suit = num / 13;
		switch (suit) {
		case 0:
			cout << "C";
			break;
		case 1:
			cout << "D";
			break;
		case 2:
			cout << "H";
			break;
		case 3:
			cout << "S";
			break;
		default:
			break;
		}
		//cout << table[this->getType()];
		cout << num % 13 +1 << " ";
	}

	cout << endl;
}

void PokerGame::sortCards() {
	//TO_DO: Sort the cards accroding to thier number
	auto num = this->playerCards;
	sort(num.begin(), num.end(), [](int a, int b) {
		return (a % 13) < (b % 13);
		}
	);
}

void PokerGame::evaluate() {
	sortCards();
	if (this->isStraight() && this->isFlush()) {
		type = StraightFlush;
	}
	else if (this->isFourOfKind()) {
		type = FourOfKind;
	}
	else if (this->isFullHouse()) {
		type = FullHouse;
	}
	else if (this->isFlush()) {
		type = Flush;
	}
	else if (this->isStraight()) {
		type = Straight;
	}
	else if (this->isThreeOfKind()) {
		type = ThreeOfKind;
	}
	else if (this->isTwoPairs()) {
		type = TwoPairs;
	}
	else if (this->isOnePair()) {
		type = OnePair;
	}
	else {
		type = HighCard;
		//TO_DO: Set the maxNumber
		this->maxNumber = this->playerCards[4];
	}
}

int PokerGame::getType() {
	return type;
}

int PokerGame::getMaxNumber() {
	return maxNumber;
}

void PokerGame::compare(int type_, int maxNumber_) {
	//TO_DO: Compare the type and output who is winner
	//Compare the type of card first. If types are the same, compare which is max the number of card.
	//If the max number is the same, compare the suit of card.
	int type1 = this->getType();
	int max1 = this->getMaxNumber();
	if (type1 > type_) cout<<"Player1 win" << endl;         //check
	else if(type1<type_) cout << "Player2 win" << endl;
	else {
		if(max1%13>maxNumber_%13) cout << "Player1 win" << endl;
		else if (max1%13<maxNumber_%13) cout << "Player2 win" << endl;
		else {
			if(max1/13>maxNumber_/13) cout << "Player1 win" << endl;
			else cout << "Player2 win" << endl;
		}
	}
}

bool PokerGame::isStraight() {
	//TO_DO: Check whether the hand of cards is Straight or not and set the maxNumber
	auto num = this->playerCards;
	if (num[0] % 13 == num[1] % 13 - 1 && num[1] % 13 == num[2] % 13 - 1 && num[2] % 13 == num[3] % 13 - 1 && num[3] % 13 == num[4] % 13 - 1) {
		this->maxNumber = num[4];
		return true;
	}
	return false;
}

bool PokerGame::isFlush() {
	//TO_DO: Check whether the hand of cards is Flush or not and set the maxNumber
	auto num = this->playerCards;
	if (num[0] / 13 == num[1] / 13 && num[1] / 13 == num[2] / 13 && num[2] / 13 == num[3] / 13 && num[3] / 13 == num[4] / 13) {
		this->maxNumber = num[4];
		return true;
	}
	return false;
}

bool PokerGame::isFourOfKind() {
	//TO_DO: Check whether the hand of cards is FourOfaKind or not and set the maxNumber
	auto num = this->playerCards;
	if (num[1]%13 == num[2]%13 && num[2]%13 == num[3]%13) {
		if (num[1]%13 == num[0]%13 || num[3]%13 == num[4]%13) {
			this->maxNumber = num[2];
			return true;
		}
	}
	return false;
}

bool PokerGame::isFullHouse() {
	//TO_DO: Check whether the hand of cards is FullHouse or not and set the maxNumber
	auto num = this->playerCards;
	if (((num[0]%13 == num[1]%13 && num[1]%13 == num[2]%13) && num[3]%13 == num[4]%13) || ((num[2]%13 == num[3]%13 && num[3]%13 == num[4]%13) && num[0]%13 == num[1]%13)) {
		this->maxNumber = num[2];
		return true;
	}
	return false;
}

bool PokerGame::isThreeOfKind() {
	//TO_DO: Check whether the hand of cards is ThreeOfaKind or not and set the maxNumber
	auto num = this->playerCards;
	if (((num[0]%13 == num[1]%13 && num[1]%13 == num[2] % 13) && num[3] % 13 != num[4] % 13) || ((num[2] % 13 == num[3] % 13 && num[3] % 13 == num[4] % 13) && num[0] % 13 != num[1] % 13)|| (num[1] % 13 == num[2] % 13 && num[2] % 13 == num[3] % 13)) {
		this->maxNumber = num[2];
		return true;
	}
	return false;
}

bool PokerGame::isTwoPairs() {
	//TO_DO: Check whether the hand of cards is TwoPairs or not and set the maxNumber
	auto num = this->playerCards;
	int cnt = 0;
	int max=0;
	for (int i = 0; i < 5; i++) {
		for (int j = i+1; j < 5; j++) {
			if (num[i] % 13 == num[j] % 13) {
				if (num[i] % 13 >= max) max = num[i] > num[j] ? num[i] : num[j];
				cnt++;
			}
		}
	}
	if (cnt == 2) {
		this->maxNumber = max;
		return true;
	}
	return false;
}

bool PokerGame::isOnePair() {
	//TO_DO: Check whether the hand of cards is OnePair or not and set the maxNumber
	auto num = this->playerCards;
	int cnt = 0;
	int max=0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (num[i] % 13 == num[j] % 13) {
				if (max <= num[i] % 13) max = num[i]>num[j]?num[i]:num[j];
				cnt++;
			}
		}
	}
	if (cnt == 1) {
		this->maxNumber = max;
		return true;
	}
	return false;
}