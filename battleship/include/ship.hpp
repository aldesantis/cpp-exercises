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

#ifndef SRC_SHIP_HPP_
#define SRC_SHIP_HPP_

/**
 * Ship
 *
 * This class represents a ship on the grid.
 */
class Ship {
	unsigned int _row; ///< The row
	unsigned int _column; ///< The column
	bool _hit; ///< Whether the ship was hit.

public:
	/**
	 * Initializes the ship.
	 *
	 * @param[in] row    The row
	 * @param[in] column The column
	 *
	 * @return Ship
	 */
	Ship(unsigned int row, unsigned int column);

	/**
	 * Returns the row.
	 *
	 * @return The row
	 */
	unsigned int getRow();

	/**
	 * Returns the column.
	 *
	 * @return The column
	 */
	unsigned int getColumn();

	/**
	 * Returns whether the ship is at the given coordinates.
	 *
	 * @param[in] row    The row to check
	 * @param[in] column The column to check
	 *
	 * @return Whether the ship is at the given coordinates
	 */
	bool isAt(unsigned int row, unsigned int column);

	/**
	 * Returns whether the ship was hit.
	 *
	 * @return Whether the ship was hit
	 */
	bool isHit();

	/**
	 * Returns whether the ship is active.
	 *
	 * @return Whether the ship is active
	 */
	bool isActive();

	/**
	 * Hits the ship.
	 */
	void hit();
};

#endif /* SRC_SHIP_HPP_ */
