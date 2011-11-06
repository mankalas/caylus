/**
 * @file   logger.hh
 * @author Vincent Boucheny <mankalas@gmail.com>
 * @date   Sun Sep 25 00:42:58 2011
 *
 * @brief  Declaration of the logger class.
 */

#ifndef LOGGER_HH
# define LOGGER_HH

# include <stack>
# include <fstream>
# include "const.hh"

namespace controller
{
	class GameEngine;
	class Player;
	class ResourceMap;
}

class Logger
{
public:

	static Logger * instance();

	void log(const std::string &msg);

	template <class T>
	std::string to_string(const T &t) const;

	void close();

	void gameInfo(const controller::GameEngine *);
	void startOfTurn(const controller::GameEngine *);
	void playerIncome(const controller::Player *, const controller::ResourceMap &);

	void startSection(int level, const std::string & title);
	void endSection();

private:
	static Logger * instance_;
	Logger();

	unsigned int turn_count_;
	std::ofstream file_;
};

# include "logger.hxx"

#endif
