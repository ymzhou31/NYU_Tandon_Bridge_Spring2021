#include <iostream>
#include <vector>
using namespace std;

/*This program generates a square grid, and initializes it with a certain amount of ants and doodlebugs. 
Ants move according to the following rules: 1) Can move one step to any empty cell each turn that is up, down, left, or right,
2) once three timesteps have passed and the ant is alive, spawn another ant in an empty cell up, down, left, or right

Doodlebugs move in the same way an ant does, except 1) if there is an ant in any cell up, down, left, or right, it will eat that ant
in its next turn. 2) it breeds only once every 8 timesteps*/

class Cell; 
class Organism;

const int GRID_DIMENSION = 20;
const int INITIAL_ANTS = 100;
const int INITIAL_DOODLEBUGS = 5;
const int MAX_RESIDENTS = GRID_DIMENSION*GRID_DIMENSION;


void time_step(Cell** grid, Organism** doodlebugs, Organism** ants, int* doodlebug_count, int* ant_count);
void print_grid(Cell** grid);

void remove_from_array(Organism* target, Organism** alive, int* count);

Cell** spawn_grid(Organism** doodlebugs, Organism** ants, int* doodlebug_count, int* ant_count);



int main() {

	Organism** doodlebugs;
	Organism** ants;
	int doodlebug_count = 0;
	int ant_count = 0;

	doodlebugs = new Organism* [MAX_RESIDENTS];
	ants = new Organism* [MAX_RESIDENTS];
	Cell** grid = spawn_grid(doodlebugs, ants, &doodlebug_count, &ant_count);
	
	print_grid(grid);
	string command;
	bool run = true;
	char userinput;
	int steps_elapsed = 0;

	while (run) {
		cout << endl << "Time steps elapsed: " << steps_elapsed++ << endl;
		cout<< endl<< "Press enter to continue. Enter any other key to exit game." << endl;
		cin.get(userinput);
		if (userinput != '\n') {
			cout << "Ending game";
			break;
		}
	
		time_step(grid, doodlebugs, ants, &doodlebug_count, &ant_count);
		print_grid(grid);
	}

}

/*Class for the units of the grid. Each cell has a pointer to its resident/a nullptr if it is empty. It also tracks an 
array of doodlebugs and an array of ants that are alive currently in the entire grid. It also tracks the counts
of the alive organisms*/
class Cell {

	int x, y;
	Organism* resident;
	char symbol;
	Organism** doodlebugs;
	Organism** ants;
	int* ant_count;
	int* doodlebug_count;

public:
	Cell() {
		x = 0, y = 0, resident = nullptr, symbol = '-'; ant_count = 0; doodlebug_count = 0;
		ants = nullptr; doodlebugs = nullptr; };

	Cell(int column, int row, Organism* input, char status, 
		Organism** input_doodlebugs, Organism** input_ants, 
		int* input_doodlebug_count, int* input_ant_count) {

		x = column, y = row, resident = input, symbol = status;
		doodlebugs = input_doodlebugs;
		ants = input_ants;
		ant_count = input_ant_count;
		doodlebug_count = input_doodlebug_count;
	}

	bool isEmpty();
	void setEmpty();
	int getX() const { return x; }
	int getY() const { return y; }
	int getSymbol() const { return symbol; }
	void setSymbol(char status) { symbol = status; }
	Organism* getResident() { return resident; }
	void setResident(Organism* input);
	Organism** getDoodlebugs() { return doodlebugs; }
	Organism** getAnts() { return ants; }
	int* getAntCount() { return ant_count; }
	int* getDoodlebugCount() { return doodlebug_count; }

};



void Cell::setResident(Organism* input) {
	resident = input;
}

bool Cell::isEmpty() {
	if (resident == nullptr) {
		return true;
	}
	return false;
}

void Cell::setEmpty() {
	setResident(nullptr);
	setSymbol('-');
}


/*Base class for Ants and Doodlebugs. Has the base attributes and functions that track and set location, status, and 
the symbol X or o associated with the derived class organism*/
class Organism {

protected:
	int x, y;
	Cell** grid;
	char symbol;
	Cell* location;
	int steps;
	string status;


	Organism() { x = 0; y = 0; grid = nullptr; symbol = NULL; location = nullptr; steps = 0; }
	void random_step();
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int newX) { x = newX; }
	void setY(int newY) { y = newY; }
	Cell** getGrid() const { return grid; }
	void setGrid(Cell** map) { grid = map; }
	void setCell(Cell* new_location) { location = new_location; setX(new_location->getX()); setY(new_location->getY()); }

public:
	int getSteps() const { return steps; }
	void setSteps(int input) { steps = input; }
	virtual char getSymbol();
	virtual void move() {};
	bool valid_coordinates(int x, int y);
	bool check_for_empty_cell(int* target_X, int* target_Y);
	string getStatus() const { return status; }
	void setStatus(string input) { status = input; }
};


char Organism::getSymbol() {
	return symbol;
}


bool Organism::check_for_empty_cell(int *target_X, int *target_Y) {

	int left, right, up, down;
	
	if (getY() - 1 > -1) { left = getY() - 1; }
	else { left = getY(); }

	if (getY() + 1 < GRID_DIMENSION) { right = getY() + 1; }
	else { right = getY(); }

	if (getX() - 1 > -1) { up = getX() - 1; }
	else { up = getX(); }

	if (getX() + 1 < GRID_DIMENSION) { down = getX() + 1; }
	else { down = getX(); }

	*target_X = getX();
	*target_Y = getY();

	if (grid[getX()][left].getSymbol() == '-') {
		*target_Y = left;
		return true;
	}
	if (grid[getX()][right].getSymbol() == '-') {
		*target_Y = right;
		return true;
	}
	if (grid[up][getY()].getSymbol() == '-') {
		*target_X = up;
		return true;
	}
	if (grid[down][getY()].getSymbol() == '-') {
		*target_X = down;
		return true;
	}

	return false;

}



void Organism::random_step() {
	
	srand(time(NULL));
	int i = rand() %4;

	int X = getX();
	int Y = getY();

	int down = X + 1;
	int right = Y + 1;
	int up = X - 1;
	int left = Y - 1;


	switch (i) {
	case 0:
		if (valid_coordinates(X, right)) { 
			getGrid()[X][Y].setEmpty();
			setCell(&getGrid()[X][right]); 
			setY(right);
			getGrid()[X][right].setResident(this);
			getGrid()[X][right].setSymbol(this->getSymbol());
		}
		break;
	case 1:
		if (valid_coordinates(down, Y)) { 
			getGrid()[X][Y].setEmpty();
			setCell(&getGrid()[down][Y]);
			getGrid()[down][Y].setResident(this);
			getGrid()[down][Y].setSymbol(this -> getSymbol());
		}	
		break;
	case 2:
		if (valid_coordinates(X, left)) { 
			getGrid()[X][Y].setEmpty();
			setCell(&getGrid()[X][left]);
			getGrid()[X][left].setResident(this);
			getGrid()[X][left].setSymbol(this -> getSymbol());
		} 
		break;
	case 3:
		if (valid_coordinates(up, Y)) {
			getGrid()[X][Y].setEmpty();
			setCell(&getGrid()[up][Y]);
			getGrid()[up][Y].setResident(this);
			getGrid()[up][Y].setSymbol(this -> getSymbol());
		} 
		break;
	}


}

bool Organism::valid_coordinates(int X, int Y) {

	if (Y < GRID_DIMENSION && X < GRID_DIMENSION && Y > -1 && X > -1 && getGrid()[X][Y].getSymbol() == '-') {
		return true;
	}

	return false;

}


class Ant : public Organism {

	char symbol = 'o';

public:
	virtual void move();

	char getSymbol() { return symbol; }
	Ant(int column, int row, Cell* cell, Cell** map) {
		setX(column), setY(row), setCell(cell), setGrid(map);
		setSteps(0);
	}
	void breed();
	
};

void Ant::breed() {

	int X, Y;

	if (check_for_empty_cell(&X, &Y)) {

		grid[X][Y].setSymbol('o');
		grid[X][Y].setResident(new Ant(x, y, &grid[X][Y], grid));
		grid[X][Y].getAnts()[*grid[X][Y].getAntCount()] = grid[X][Y].getResident();
		(*grid[X][Y].getAntCount()) += 1;
	}

	setStatus("newBorn");
	(*grid[X][Y].getResident()).setStatus("newBorn");
	setSteps(0);
}

void Ant::move() {
	if (getSteps() >= 3) {
		breed();
		setSteps(0);
	}
	else {
		Organism::random_step();
		setSteps(getSteps() + 1);
	}
}

class Doodlebug : public Organism {
	
	char symbol = 'X';
	int steps_since_meal;

public:
	char getSymbol() { return symbol; }
	virtual void move();
	void move(int X, int Y);
	Doodlebug(int column, int row, Cell* cell, Cell** map) {
		setX(column), setY(row), setCell(cell), setGrid(map);
		steps_since_meal = 0;
		steps=0;
	}
	void eat(int targetX, int targetY, Organism** ants, int* ant_count);
	int get_steps_since_meal() {return steps_since_meal; }
	void set_steps_since_meal(int input) { steps_since_meal = input; }
	void starve();
	void breed();
	bool check_surrounding(int* target_X, int* target_Y);
	
};

void Doodlebug::breed() {

	int X, Y;

	if (check_for_empty_cell(&X, &Y)) {

		grid[X][Y].setSymbol('X');
		grid[X][Y].setResident(new Doodlebug(x, y, &grid[X][Y], grid));
		grid[X][Y].getDoodlebugs()[*grid[X][Y].getDoodlebugCount()] = grid[X][Y].getResident();
		(*grid[X][Y].getDoodlebugCount()) += 1;
		grid[X][Y].getResident()->setStatus("newBorn");
	}

	set_steps_since_meal(get_steps_since_meal() + 1);
	setStatus("newBorn");
	setSteps(0);
}


void Doodlebug::move(int X, int Y) {
	location->setEmpty();
	setCell(&grid[X][Y]);
	setX(X); setY(Y);
	location->setSymbol('X');
}

void Doodlebug::starve() {

	grid[getX()][getY()].setEmpty();
	remove_from_array(this, location->getDoodlebugs(), location->getDoodlebugCount());

}
bool Doodlebug::check_surrounding(int* target_X, int* target_Y) {
	
	int left, right, up, down;

	if (getY() - 1 > -1) { left = getY() - 1; }
	else { left = getY(); }

	if (getY() + 1 < GRID_DIMENSION) { right = getY() + 1; }
	else { right = getY(); }
	
	if (getX() - 1 > -1) { up = getX() - 1; }
	else { up = getX(); }
	
	if (getX() + 1 < GRID_DIMENSION) { down = getX() + 1; }
	else { down = getX(); }

	*target_X = getX();
	*target_Y = getY();

	if (grid[getX()][left].getSymbol() == 'o') {
		*target_Y = left;
		return true;
	}
	if (grid[getX()][right].getSymbol() == 'o') {
		*target_Y = right;
		return true;
	}
	if (grid[up][getY()].getSymbol() == 'o') {
		*target_X = up;
		return true;
	}
	if (grid[down][getY()].getSymbol() == 'o') {
		*target_X = down;
		return true;
	}

	return false;

}

void Doodlebug::eat(int targetX, int targetY, Organism** ants, int* ant_count) {

	Organism* target = grid[targetX][targetY].getResident();
	remove_from_array(target, ants, ant_count);
	grid[targetX][targetY].setEmpty();
	move(targetX, targetY);
	set_steps_since_meal(0);
	setSteps(getSteps() + 1);

}



void Doodlebug :: move() {

	int targetX;
	int targetY;

	if (check_surrounding(&targetX, &targetY)) {
		eat(targetX, targetY, grid[targetX][targetY].getAnts(), grid[targetX][targetY].getAntCount());
	}
	else if (get_steps_since_meal() >= 3) {
		starve();
	}
	else if (getSteps() >= 8) {
		breed();
		set_steps_since_meal(get_steps_since_meal() + 1);
	}
	else {
		Organism::random_step();
		set_steps_since_meal(get_steps_since_meal() + 1);
		setSteps(getSteps() + 1);
	}
}


/*iterates through array of Organisms until it finds the pointer in the parameter, deletes it
and shifts the remaining elements in the array to the left*/
void remove_from_array(Organism* target, Organism** alive, int* count) {

	bool shift = false;

	for (int i = 0; i < *count; i++) {
		if (target == alive[i]) {
			shift = true;
			delete alive[i];
			target = nullptr;
			(*count) -= 1;
		}
		if (shift) {
			alive[i] = alive[i + 1];
			alive[i + 1] = alive[i + 2];
		}
		
	}

}

Cell** spawn_grid(Organism** doodlebugs, Organism** ants, int* doodlebug_count, int* ant_count) {

	Cell** grid;

	grid = new Cell* [GRID_DIMENSION];

	for (int i = 0; i < GRID_DIMENSION; i++) {
		grid[i] = new Cell[GRID_DIMENSION];
		for (int j = 0; j < GRID_DIMENSION; j++) {
			grid[i][j] = Cell(i, j, nullptr, '-', doodlebugs, ants, doodlebug_count, ant_count);
		}
	}

	
	for (int i = 0; i < INITIAL_ANTS;) {
		int x = rand() % GRID_DIMENSION;
		int y = rand() % GRID_DIMENSION;

		if (grid[x][y].getSymbol() == '-') {
			grid[x][y].setSymbol('o');
			grid[x][y].setResident(new Ant(x, y, &grid[x][y], grid));
			ants[i] = grid[x][y].getResident();
			(*ant_count) += 1;
			i++;
		}
	}

	for (int i = 0; i < INITIAL_DOODLEBUGS;) {
		int x = rand() % GRID_DIMENSION;
		int y = rand() % GRID_DIMENSION;

		if (grid[x][y].getSymbol() == '-') {
			grid[x][y].setSymbol('X');
			grid[x][y].setResident(new Doodlebug(x, y, &grid[x][y], grid));
			doodlebugs[i] = grid[x][y].getResident();
			(*doodlebug_count) += 1;
			i++;
		}
	}
	
	return grid;

}



void time_step(Cell** grid, Organism** doodlebugs, Organism** ants, int* doodlebug_count, int* ant_count) {
	
	int original_doodlebug_count = *doodlebug_count;

	for (int i = 0; i < *doodlebug_count;) {
		if (doodlebugs[i]->getStatus() == "newBorn") {
			doodlebugs[i]->setStatus("mature");
			i++;
		}
		else {
			doodlebugs[i]->move();
			if (original_doodlebug_count > *doodlebug_count) {
				original_doodlebug_count--;
			}
			else {
				i++;
			}
		}
	}

	int original_ant_count = *ant_count;
	for (int i = 0; i < *ant_count;) {
		if (ants[i]->getStatus() == "newBorn") {
			ants[i]->setStatus("mature");
			i++;
		}
		else {
			ants[i]->move();
			if (original_ant_count > *ant_count) {
				original_ant_count--;
			}
			else {
				i++;
			}
		}
	}
}

void print_grid(Cell** grid) {

	for (int i = 0; i < GRID_DIMENSION; i++) {
		for (int j = 0; j < GRID_DIMENSION; j++) {
			cout << (char)(grid[i][j].getSymbol())<<"  ";
		} 
		cout << endl;
	}

}