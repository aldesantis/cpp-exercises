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

#include <iostream>
#include <vector>

#include <ship.hpp>
#include <grid.hpp>

Grid grid = Grid(10, 5);

void printGrid() {
	std::vector<Ship*> ships = grid.getShips();

	for (unsigned int i = 0; i < ships.size(); i++) {
		Ship* ship = ships[i];
		std::cout << "Ship at [" << ship->getRow() << ", " << ship->getColumn() << "]: ";

		if (ship->isHit()) {
			std::cout << "HIT";
		} else {
			std::cout << "ACTIVE";
		}

		std::cout << std::endl;
	}
}

void shoot() {
	unsigned int row, column;

	do {
		std::cout << "Insert row: ";
		std::cin >> row;

		std::cout << "Insert column: ";
		std::cin >> column;
	} while (!grid.isValidPosition(row, column));

	if (grid.hit(row, column)) {
		std::cout << "You hit a ship!" << std::endl;
	} else {
		std::cout << "You didn't hit any ships!" << std::endl;
	}
}

int main() {
	unsigned int choice;

	for (unsigned int i = 0; i < 2; i++) {
		grid.createShipAtRandom();
	}

	do {
		std::cout << "What do you want to do?" << std::endl;

		std::cout << "1. Print grid" << std::endl;
		std::cout << "2. Shoot" << std::endl;
		std::cout << "0. Exit" << std::endl;

		std::cout << "Insert choice: ";
		std::cin >> choice;

		switch (choice) {
			case 1:
				printGrid();
				break;

			case 2:
				shoot();
				break;

			case 0:
				break;

			default:
				std::cout << "Invalid choice." << std::endl;
		}
	} while (choice != 0 && grid.hasActiveShips());

	return 0;
}
