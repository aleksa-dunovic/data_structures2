/**
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include "matrix.h"
# include "A2.h"

//-----------------------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid square matrix
 * 		A square matrix is a matrix which the number of rows is the same as the number of columns
 * 		Note that an empty matrix is a square matrix of size 0x0
 */

int is_square() {
	// Check to see if it's a valid matrix
	if (is_matrix() == 0)
		return False;

	int i, j, row, col;

	// Get the size of the matrix
	row = get_row_length(0);
	col = get_column_length(0);

	// Both dimensions must be equal
	if (row != col)
		return False;

	// Check that the col and row length is the same for all cols and rows
	for (i = 1; i < row; i++) {
		if (get_row_length(i) != row || get_column_length(i) != col)
			return False;
	}

	// Check that anything outside of the matrix is set to null (-1)
	for (i = row; i < SIZE; i++) {
		for (j = row; j < SIZE; j++) {
			if (get_element(i, j) != -1)
				return False;
		}

	}
	return True;
}
//-----------------------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid identity matrix
 * 		An identity matrix is a square matrix, all diagonal elements equal to 1,
 * 			all other elements equal to 0
 * 		Note that an empty matrix is NOT an identity matrix
 */

int is_identity() {
	// Check to see if it's a valid and non-empty matrix
	if (is_matrix() == 0 || is_empty() == 1)
		return False;

	int i, j, len;
	len = get_row_length(0);

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			// When on the diagonal the value must be 1
			if (i == j) {
				if (get_element(i, j) != 1)
					return False;

			}
			// When outside of the diagonal the value must be 0
			else {
				if (get_element(i, j) != 0)
					return False;

			}
		}
	}
	return True;
}
//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid uniform matrix
 * 		A uniform matrix is a matrix in which all elements are equal
 * 		Note that an empty matrix is NOT a uniform matrix
 */
int is_uniform() {
	// Check to see if it's a valid and non-empty matrix
	if (is_matrix() == 0 || is_empty() == 1)
		return False;

	int i, j, rows, cols, value;
	rows = get_row_length(0);
	cols = get_column_length(0);
	value = get_element(0, 0);
	for (i = 0; i < cols; i++) {
		for (j = 0; j < rows; j++) {
			if (get_element(i, j) != value) {
				return False;
			}
		}
	}
	return True;
}
//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid unique matrix
 * 		A unique matrix is a matrix in which all elements have unique values
 * 			i.e. no two elements have equal value
 * 		Note that an empty matrix is NOT a unique matrix
 */

int is_unique() {
	// Check to see if it's a valid and non-empty matrix
	if (is_matrix() == 0 || is_empty() == 1)
		return False;

	int i, j, k, rows, cols, temp;
	rows = get_row_length(0);

	cols = get_column_length(0);
	// Step 1: Iterate through each element
	for (i = 0; i < cols; i++) {
		for (j = 0; j < rows; j++) {

			// Step 2: Store an element in a temp variable and set the value in the matrix to 0
			temp = get_element(i, j);
			set_element(i, j, 0);

			//  Step 3: Search each row for the temp value. This will tells us if the element appears more than once
			for (k = 0; k < SIZE; k++) {

				// If the element is found this can't be a unique matrix. So, we return the temp value and return False
				if (contains(matrix[k], temp)) {
					set_element(i, j, temp);
					return False;
				}
			}
			// If we get to this point it means the element is unique, so we just return it to the matrix
			set_element(i, j, temp);
		}
	}
	return True;
}

//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid symmetric matrix
 * 		A symmetric matrix is a matrix which equals to its transpose
 * 		Note that an empty matrix is a VALID symmetric matrix
 */
int is_symmetric() {
	// Check to see if it's a valid matrix
	if (is_matrix() == 0)
		return False;

	int i, j, rows, cols;

	rows = get_row_length(0);
	cols = get_column_length(0);

	for (i = 0; i < cols; i++) {
		for (j = 0; j < rows; j++) {
			// Loop through all elements and make sure the ij = ji
			if (get_element(i, j) != get_element(j, i)) {
				return False;
			}
		}
	}
	return True;
}

//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid binary matrix
 * 		A binary matrix is a matrix which all of its elements are equal to either 1 or 0
 * 		Note that an empty matrix is NOT a binary matrix
 */
int is_binary() {
	// Check to see if it's a valid and non-empty matrix
	if (is_matrix() == 0 || is_empty() == 1)
		return False;

	int i, j, rows, cols;

	rows = get_row_length(0);
	cols = get_column_length(0);

	for (i = 0; i < cols; i++) {
		for (j = 0; j < rows; j++) {
			// Loop through all elements and make sure they equal 1 or 0
			if (get_element(i, j) != 0 && get_element(i, j) != 1) {
				return False;
			}
		}
	}
	return True;
}

//---------------------------------------------------------
/**
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid incremental matrix
 * 		An incremental matrix is:
 * 		a matrix which every element is greater than or equal to the one before it
 * 		Order: left to right, then top to bottom.
 */
int is_incremental() {
	// Check to see if it's a valid and non-empty matrix
	if (is_matrix() == 0 || is_empty() == 1)
		return False;

	int i, j, rows, cols, max;

	rows = get_row_length(0);
	cols = get_column_length(0);
	max = get_element(0, 0);

	for (i = 0; i < cols; i++) {
		for (j = 0; j < rows; j++) {
			// Make sure that the current element is always greater than or equal to the max
			if (get_element(i, j) < max) {
				return False;
			}
			// Set the current element to max
			max = get_element(i, j);
		}
	}
	return True;
}
