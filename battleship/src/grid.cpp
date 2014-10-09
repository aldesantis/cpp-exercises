/*
 * Copyright (c) 2014 Alessandro Desantis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <random>

#include <grid.hpp>
#include <ship.hpp>

int Grid::getRandomInteger(int min, int max) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(min, max);

	auto random_integer = distr(eng);

	return random_integer;
}

unsigned int Grid::getRandomRow() {
	return getRandomInteger(0, getRows() - 1);
}

unsigned int Grid::getRandomColumn() {
	return getRandomInteger(0, getColumns() - 1);
}

Grid::Grid(unsigned int rows, unsigned int columns) {
	_rows = rows;
	_columns = columns;
}

unsigned int Grid::getRows() {
	return _rows;
}

unsigned int Grid::getColumns() {
	return _columns;
}

unsigned int Grid::getSize() {
	return getRows() * getColumns();
}

bool Grid::isValidPosition(unsigned int row, unsigned int column) {
	return (row <= (getRows() - 1) && (column <= getColumns() - 1));
}

bool Grid::isFull() {
	return (_ships.size() == getSize());
}

Ship* Grid::createShipAt(unsigned int row, unsigned int column) {
	if (!isValidPosition(row, column) || hasShipAt(row, column)) {
		throw 20;
	}

	Ship* ship = new Ship(row, column);
	_ships.push_back(ship);

	return ship;
}

Ship* Grid::createShipAtRandom() {
	unsigned int row, column;

	if (isFull()) {
		throw 20;
	}

	do {
		row = getRandomRow();
		column = getRandomColumn();
	} while (hasShipAt(row, column));

	return createShipAt(row, column);
}

std::vector<Ship*> Grid::getShips() {
	return _ships;
}

bool Grid::hasShipAt(unsigned int row, unsigned int column) {
	for (unsigned int i = 0; i < _ships.size(); i++) {
		if (_ships[i]->isAt(row, column)) {
			return true;
		}
	}

	return false;
}

Ship* Grid::getShipAt(unsigned int row, unsigned int column) {
	for (unsigned int i = 0; i < _ships.size(); i++) {
		if (_ships[i]->isAt(row, column)) {
			return _ships[i];
		}
	}

	throw 20;
}

bool Grid::hit(unsigned int row, unsigned int column) {
	if (!hasShipAt(row, column)) {
		return false;
	}

	Ship* ship = getShipAt(row, column);

	if (ship->isHit()) {
		return false;
	}

	ship->hit();

	return true;
}

bool Grid::hasActiveShips() {
	for (unsigned int i = 0; i < _ships.size(); i++) {
		if (_ships[i]->isActive()) {
			return true;
		}
	}

	return false;
}
