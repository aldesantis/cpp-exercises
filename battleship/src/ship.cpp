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

#include <ship.hpp>

Ship::Ship(unsigned int row, unsigned int column) {
	_row = row;
	_column = column;
	_hit = false;
}

unsigned int Ship::getRow() {
	return _column;
}

unsigned int Ship::getColumn() {
	return _row;
}

bool Ship::isAt(unsigned int row, unsigned int column) {
	return (getRow() == row && getColumn() == column);
}

bool Ship::isHit() {
	return _hit;
}

bool Ship::isActive() {
	return !_hit;
}

void Ship::hit() {
	_hit = true;
}
