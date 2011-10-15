/**
 * @file   human.cc
 * @author Vincent Boucheny <mankalas@gmail.com>
 * @date   Dec 14 22:21:10 2011
 *
 * @brief  Declaration of the human class.
 */

#include "human.hh"

#include <iostream>
#include "logger.hh"

using namespace std;
using namespace view;
using namespace controller;

Human::Human(GameEngine *ge)
	: View(ge)
{
}

Human::~Human()
{
}

string Human::askName() const
{
	user_interface_->showMessage("What name?");
	return user_interface_->getString();
}

bool Human::askYesNo() const
{
	return true;
}

bool Human::askJoustField() const
{
	return true;
}

/********void Human::_connectSignals()
	 {
	 ge_->connectNbHumansSignal(boost::bind(&Human::askNbHumans, this, _1));
	 ge_->connectNbAIsSignal(boost::bind(&Human::askNbAIs, this, _1, _2));
	 ge_->connectBoardUpdatedSignal(boost::bind(&Human::updateBoard, this));
	 }*/

void Human::operator()()
{
	//  boost::mutex mut;
	//boost::unique_lock<boost::mutex> lock(mut);
	//disconnected_->wait(lock);
}

boost::signal<unsigned (unsigned)>::slot_function_type Human::getAskNbHumansSlot() const
{
	return boost::bind(&Human::askNbHumans, this, _1);
}

boost::signal<unsigned (unsigned, unsigned)>::slot_function_type Human::getAskNbAIsSlot() const
{
	return boost::bind(&Human::askNbAIs, this, _1, _2);
}

unsigned Human::askNbHumans(unsigned max) const
{
	Logger::log("Asking nb humans.");
	unsigned nb_humans = 0;
	while ((cout << "How many humans? (" << max << " max)\n") &&
	       (!(cin >> nb_humans) || (nb_humans > max)))
	{
		cout << "Bad number (0 min, " << max << "max).\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return nb_humans;
}

unsigned Human::askNbAIs(unsigned min, unsigned max) const
{
	unsigned nb_ai = min;
	while ((cout << "How many AIs? (" << min << " min, " << max << " max)\n") &&
	       (!(cin >> nb_ai) || (nb_ai > max) || (nb_ai < min)))
	{
		cout << "Bad number (" << min << " min, " << max << " max).\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return nb_ai;
}

void Human::updateBoard() const
{
	user_interface_->updateBoard();
}


int Human::askProvostShift() const
{
	return 3;
}

bool Human::isHuman() const
{
	return true;
}

boost::signal<void (void)>::slot_function_type Human::getUpdateBoardSlot() const
{
	return boost::bind(&Human::updateBoard, this);
}

BoardElement*
Human::askWorkerPlacement(const std::vector<BoardElement*> buildings) const
{
	return buildings[0];//this->user_interface_->askBuilding(buildings);
}

unsigned Human::askBuilding() const
{
	return 3;
}

unsigned Human::askResourceChoice() const
{
	return 0;
}

