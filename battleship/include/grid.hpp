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

#include <vector>

#include <ship.hpp>

#ifndef SRC_GRID_HPP_
#define SRC_GRID_HPP_

/**
 * Grid
 *
 * A grid is an X by Y matrix containing zero or more ships.
 */
class Grid {
	unsigned int _rows; ///< The number of rows
	unsigned int _columns; ///< The number of columns
	std::vector<Ship*> _ships; ///< The ships

	/**
	 * Returns a random integer in the given range.
	 *
	 * @param[in] min Minimum
	 * @param[in] max Maximum
	 *
	 * @return A random integer
	 */
	int getRandomInteger(int min, int max);

	/**
	 * Returns a random row.
	 *
	 * @return A random row
	 */
	unsigned int getRandomRow();

	/**
	 * Returns a random column.
	 *
	 * @return A Random column
	 */
	unsigned int getRandomColumn();

public:
	/**
	 * Initializes the grid.
	 */
	Grid(unsigned int rows, unsigned int columns);

	/**
	 * Returns the number of rows.
	 *
	 * @return The number of rows
	 */
	unsigned int getRows();

	/**
	 * Returns the number of columns.
	 *
	 * @return The number of columns
	 */
	unsigned int getColumns();

	/**
	 * Returns the grid's size.
	 *
	 * @return The size
	 */
	unsigned int getSize();

	/**
	 * Returns whether the given position is valid.
	 *
	 * @param[in] row    The row to check
	 * @param[in] column The column to check
	 *
	 * @return Whether the position is valid
	 */
	bool isValidPosition(unsigned int row, unsigned int column);

	/**
	 * Returns whether the grid is full.
	 *
	 * @return Whether the grid is full
	 */
	bool isFull();

	/**
	 * Creates a ship at the given position.
	 *
	 * @param[in] row    The row
	 * @param[in] column The column
	 *
	 * @return Ship The ship
	 */
	Ship* createShipAt(unsigned int row, unsigned int column);

	/**
	 * Creates a ship at a random position.
	 *
	 * @return Ship The ship
	 */
	Ship* createShipAtRandom();

	/**
	 * Returns the ships.
	 *
	 * @return The ships
	 */
	std::vector<Ship*> getShips();

	/**
	 * Returns whether there is a ship at the given position.
	 *
	 * @param[in] row    The row to check
	 * @param[in] column The column to check
	 *
	 * @return Whether there is a ship at the given position
	 */
	bool hasShipAt(unsigned int row, unsigned int column);

	/**
	 * Returns the ship at the given position.
	 *
	 * @param[in] row    The row to retrieve
	 * @param[in] column The column to retrieve
	 *
	 * @return The ship at the given position
	 */
	Ship* getShipAt(unsigned int row, unsigned int column);

	/**
	 * Tries to hit a ship at the given position.
	 *
	 * @param[in] row    The row
	 * @param[in] column The column
	 *
	 * @return bool Whether a ship was hit
	 */
	bool hit(unsigned int row, unsigned int column);

	/**
	 * Returns whether the grid has any active ships.
	 *
	 * @return Whether the grid has any active ships
	 */
	bool hasActiveShips();
};

#endif /* SRC_GRID_HPP_ */
