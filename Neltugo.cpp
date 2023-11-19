//Please help me


#include <iostream>
#include <conio.h>
#include<Windows.h>
using namespace std; // Adding the namespace


class Cell {
public:
    string cellData;
    Cell* rightCell;
    Cell* downCell;
    Cell* leftCell;
    Cell* upCell;


    Cell(const string& value) : cellData(value), rightCell(nullptr), downCell(nullptr), leftCell(nullptr), upCell(nullptr) {}
};


class MiniExcel {
public:
    int totalRows;
    int totalCols;
    Cell* currentCell;
    int currentRow;
    int currentCol;


    MiniExcel(int numRows, int numCols) : totalRows(numRows), totalCols(numCols) {
        currentCell = createGrid(totalRows, totalCols);
        currentRow = 0;
        currentCol = 0;
    }


    Cell* createGrid(int numRows, int numCols) {
        Cell* head = new Cell("0");
        Cell* currentRowCell = head;


        for (int i = 0; i < numRows; ++i) {
            Cell* currentColCell = currentRowCell;
            for (int j = 0; j < numCols; ++j) {
                Cell* newCell = new Cell("0");
                currentColCell->rightCell = newCell;
                currentColCell = currentColCell->rightCell;
            }


            if (i < numRows - 1) {
                Cell* newRowCell = new Cell("0");
                currentRowCell->downCell = newRowCell;
                currentRowCell = currentRowCell->downCell;
            }
        }


        return head;
    }


    void printGrid() {
        Cell* currentRowCell = currentCell;
        for (int i = 0; i < totalRows; ++i) {
            Cell* currentColCell = currentRowCell;


            for (int j = 0; j < totalCols; ++j) {
                if (i == currentRow && j == currentCol) {
                    cout << "[" << currentColCell->cellData << "]\t";
                }
                else {
                    cout << currentColCell->cellData << "\t";
                }
                currentColCell = currentColCell->rightCell;
            }


            cout << endl;
            currentRowCell = currentRowCell->downCell;
        }
    }


    void InsertRowAbove() {
        // Create a new row with the same number of columns as the existing grid
        Cell* newRow = createRow(totalCols);


        // Update the links between the newly inserted row and the current row
        Cell* currentRowCell = currentCell;
        Cell* previousRowCell = nullptr;


        // Find the row immediately above the current row
        while (currentRowCell != nullptr && currentRowCell != currentCell) {
            previousRowCell = currentRowCell;
            currentRowCell = currentRowCell->downCell;
        }


        // Insert the new row above the current row
        if (previousRowCell != nullptr) {
            newRow->downCell = currentRowCell;
            previousRowCell->downCell = newRow;
        }
        else {
            newRow->downCell = currentRowCell;
            currentCell = newRow; // Update the currentCell pointer
        }


        // Increment the total number of rows
        totalRows++;


        // Update the current row index
        currentRow++;
    }
    void InsertRowBelow() {
        // Create a new row with the same number of columns as the existing grid
        Cell* newRow = createRow(totalCols);


        // Find the row immediately below the current row
        Cell* currentRowCell = currentCell;
        while (currentRowCell != nullptr && currentRowCell->downCell != nullptr) {
            currentRowCell = currentRowCell->downCell;
        }


        // Insert the new row below the current row
        if (currentRowCell != nullptr) {
            currentRowCell->downCell = newRow;
        }
        else {
            // If there is no row below the current row, insert the new row as the last row
            currentCell->downCell = newRow;
            currentCell = newRow;
        }


        // Increment the total number of rows
        totalRows++;
    }
    void InsertColumnRight() {
        // Create a new column with the same number of rows as the existing grid
        Cell* newColumn = createColumn(totalRows);


        // Update the links between the newly inserted column and the current column
        Cell* currentColumnCell = currentCell;
        Cell* previousColumnCell = nullptr;


        // Find the column immediately to the right of the current column
        while (currentColumnCell != nullptr && currentColumnCell != currentCell) {
            previousColumnCell = currentColumnCell;
            currentColumnCell = currentColumnCell->rightCell;
        }
        // Insert the new column to the right of the current column
        if (previousColumnCell != nullptr) {
            newColumn->rightCell = currentColumnCell;
            previousColumnCell->rightCell = newColumn;
        }
        else {
            newColumn->rightCell = currentColumnCell;
            currentCell = newColumn; // Update the currentCell pointer
        }


        // Increment the total number of columns
        totalCols++;


        // Update the current column index
        currentCol++;
    }


    void InsertColumnLeft() {
        // Create a new column with the same number of rows as the existing grid
        Cell* newColumn = createColumn(totalRows);


        // Find the column immediately to the left of the current column
        Cell* currentColumnCell = currentCell;
        while (currentColumnCell != nullptr && currentColumnCell->leftCell != nullptr) {
            currentColumnCell = currentColumnCell->leftCell;
        }


        // Insert the new column to the left of the current column
        if (currentColumnCell != nullptr) {
            currentColumnCell->leftCell = newColumn;
        }
        else {
            // If there is no column to the left of the current column, insert the new column as the first column
            currentCell->leftCell = newColumn;
            currentCell = newColumn;
        }


        // Increment the total number of columns
        totalCols++;
    }


    Cell* createColumn(int numRows) {
        Cell* newColumn = new Cell("0");
        Cell* currentCellInColumn = newColumn;


        for (int i = 1; i < numRows; ++i) {
            Cell* newCell = new Cell("0");
            currentCellInColumn->downCell = newCell;
            currentCellInColumn = newCell;
        }


        return newColumn;
    }
    Cell* createRow(int numCols) {
        Cell* newRow = new Cell("0");
        Cell* currentCellInRow = newRow;


        for (int i = 1; i < numCols; ++i) {
            Cell* newCell = new Cell("0");
            currentCellInRow->rightCell = newCell;
            currentCellInRow = newCell;
        }


        return newRow;
    }


    void DeleteRow() {
        if (totalRows <= 1) {
            // Ensure there is at least one row
            return;
        }


        // Find the current row to be deleted
        Cell* currentRowCell = currentCell;
        Cell* previousRowCell = nullptr;


        while (currentRowCell != nullptr && currentRowCell != currentCell) {
            previousRowCell = currentRowCell;
            currentRowCell = currentRowCell->downCell;
        }


        // Update the links to bypass the current row
        if (previousRowCell != nullptr) {
            previousRowCell->downCell = currentRowCell->downCell;
        }
        else {
            // If the current row is the first row, update the currentCell pointer
            currentCell = currentCell->downCell;
        }


        // Delete the current row
        deleteRowCells(currentRowCell);


        // Decrement the total number of rows
        totalRows--;


        // Ensure the current row index is within bounds
        if (currentRow >= totalRows) {
            currentRow = totalRows - 1;
        }
    }


    void deleteRowCells(Cell* startCell) {
        if (!startCell) {
            return;
        }


        Cell* currentCell = startCell;
        while (currentCell != nullptr) {
            Cell* nextCell = currentCell->rightCell; // Move right to the next cell in the same row
            delete currentCell;
            currentCell = nextCell;
        }
    }


    void DeleteColumn() {
        if (totalCols <= 1) {
            // Ensure there is at least one column
            return;
        }


        // Find the current column to be deleted
        Cell* currentColumnCell = currentCell;
        Cell* previousColumnCell = nullptr;


        while (currentColumnCell != nullptr && currentColumnCell != currentCell) {
            previousColumnCell = currentColumnCell;
            currentColumnCell = currentColumnCell->rightCell;
        }


        // Update the links to bypass the current column
        if (previousColumnCell != nullptr) {
            previousColumnCell->rightCell = currentColumnCell->rightCell;
        }
        else {
            // If the current column is the first column, update the currentCell pointer
            currentCell = currentColumnCell->rightCell;
        }


        // Delete the current column
        deleteColumnCells(currentColumnCell);


        // Decrement the total number of columns
        totalCols--;


        // Ensure the current column index is within bounds
        if (currentCol >= totalCols) {
            currentCol = totalCols - 1;
        }
    }


    void deleteColumnCells(Cell* startCell) {
        if (!startCell) {
            return;
        }


        Cell* currentCell = startCell;
        while (currentCell != nullptr) {
            Cell* nextCell = currentCell->downCell; // Move down to the next cell in the same column
            delete currentCell;
            currentCell = nextCell;
        }
    }
    void ClearRow() {
        // Find the current row
        Cell* currentRowCell = currentCell;


        while (currentRowCell != nullptr && currentRowCell != currentCell) {
            currentRowCell = currentRowCell->downCell;
        }


        // Clear the data in all cells in the current row
        clearRowCells(currentRowCell);
    }


    void clearRowCells(Cell* startCell) {
        Cell* currentCell = startCell;
        while (currentCell != nullptr) {
            currentCell->cellData = "1"; // Set cell data to empty
            currentCell = currentCell->rightCell; // Move to the next cell in the same row
        }
    }
    void moveUp() {
        if (currentRow > 0) {
            currentRow--;
        }
    }


    void moveDown() {
        if (currentRow < totalRows - 1) {
            currentRow++;
        }
    }


    void moveLeft() {
        if (currentCol > 0) {
            currentCol--;
        }
    }


    void moveRight() {
        if (currentCol < totalCols - 1) {
            currentCol++;
        }
    }
};


int main() {
    MiniExcel excel(5, 5);
    excel.printGrid();


    int key;
    while (true) {
        if (_kbhit()) {
            key = _getch();
            switch (key) {
            case 72: // Up arrow key
                excel.moveUp();
                break;
            case 80: // Down arrow key
                excel.moveDown();
                break;
            case 75: // Left arrow key
                excel.moveLeft();
                break;
            case 77: // Right arrow key
                excel.moveRight();
                break;
            case 'p': // Insert row above (for example, you can use 'I' key)
                excel.InsertRowAbove();
                break;
            case 'n':
                excel.InsertRowBelow();
                break;
            case 'm': // Insert row above (for example, you can use 'I' key)
                excel.InsertColumnLeft();
                break;
            case 'u':
                excel.InsertColumnRight();
                break;
            case 'd': // Delete the current row
                excel.DeleteRow();
                break;
            case 'c': // Delete the current column
                excel.DeleteColumn();
                break;
            case 'x': // Clear the current row
                excel.ClearRow();
                break;
            case 27: // ESC key to exit
                return 0;
            }
            system("cls");
            excel.printGrid();
        }
    }


    return 0;
}
