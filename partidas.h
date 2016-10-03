#ifndef PARTIDAS_H_INCLUDED
#define PARTIDAS_H_INCLUDED

int SudokuFacil[][9] =     {{2,6,0,  7,0,0,  0,9,3},
                            {0,0,0,  0,1,0,  0,0,0},
                            {0,0,7,  0,0,4,  8,0,0},

                            {0,0,8,  6,9,2,  0,0,4},
                            {0,4,0,  0,0,0,  0,6,0},
                            {7,0,0,  5,4,8,  2,0,0},

                            {0,0,4,  3,0,0,  7,0,0},
                            {0,0,0,  0,2,0,  0,0,0},
                            {9,2,0,  0,0,1,  0,8,6},
                            //--------------------//
                            {0,1,0,  7,0,3,  0,5,0},
                            {7,0,0,  0,8,0,  0,0,6},
                            {0,0,8,  5,0,0,  4,0,0},

                            {3,0,0,  0,0,0,  7,0,5},
                            {0,4,0,  0,7,0,  0,3,0},
                            {9,0,2,  0,0,0,  0,0,4},

                            {0,0,7,  0,0,5,  8,0,0},
                            {1,0,0,  0,4,0,  0,0,9},
                            {0,3,0,  9,0,6,  0,1,0},
                            //--------------------//
                            {7,0,0,  9,8,0,  0,0,2},
                            {0,5,0,  6,0,0,  0,7,0},
                            {0,0,3,  0,1,0,  6,0,0},

                            {0,0,0,  0,2,0,  0,9,6},
                            {2,0,5,  0,0,0,  3,0,1},
                            {9,8,0,  0,5,0,  0,0,0},

                            {0,0,9,  0,6,0,  7,0,0},
                            {0,1,0,  0,0,9,  0,4,0},
                            {3,0,0,  0,7,2,  0,0,5}};

//------------------------------------------------------------------
int SudokuMedio[][9] =
                           {{6,1,0,  0,8,0,  2,7,0},
                            {9,0,0,  0,0,0,  0,0,0},
                            {0,0,0,  1,2,0,  3,0,0},

                            {0,0,0,  0,0,0,  0,3,0},
                            {4,2,0,  7,0,5,  0,6,1},
                            {7,5,0,  0,0,0,  0,0,0},

                            {0,0,6,  0,1,4,  0,0,0},
                            {0,0,0,  0,0,0,  0,0,9},
                            {0,4,5,  0,9,0,  0,8,7},
                            //--------------------//
                            {0,0,0,  0,4,0,  9,8,0},
                            {1,8,0,  0,0,0,  0,5,0},
                            {2,0,0,  7,0,0,  0,0,0},

                            {0,0,0,  0,7,0,  4,0,0},
                            {4,0,0,  8,0,9,  0,0,3},
                            {0,0,1,  0,3,0,  0,0,0},

                            {0,0,0,  0,0,3,  0,0,5},
                            {0,7,0,  0,0,0,  0,4,9},
                            {0,3,6,  0,9,0,  0,0,0},
                            //--------------------//
                            {0,6,0,  1,0,4,  0,5,0},
                            {0,0,8,  3,0,5,  6,0,0},
                            {2,0,0,  0,0,0,  0,0,1},

                            {8,0,0,  4,0,0,  0,0,6},
                            {0,0,6,  0,0,0,  3,0,0},
                            {7,0,0,  9,0,1,  0,0,4},

                            {5,0,0,  0,0,0,  0,0,2},
                            {0,0,7,  2,0,6,  9,0,0},
                            {0,4,0,  5,0,8,  0,7,0}};


int SudokuDificil[][9] =
                           {{6,0,0,  5,0,1,  0,0,8},
                            {0,4,0,  0,7,0,  0,6,0},
                            {0,0,9,  0,0,0,  5,0,0},

                            {3,0,0,  0,0,0,  0,0,4},
                            {0,0,0,  6,0,3,  0,0,0},
                            {5,0,0,  0,0,0,  0,0,7},

                            {0,0,7,  0,0,0,  3,0,0},
                            {0,9,0,  0,1,0,  0,4,0},
                            {4,0,0,  2,0,8,  0,0,1},
                            //--------------------//
                            {0,3,0,  0,0,1,  0,6,0},
                            {5,0,1,  3,0,0,  0,0,9},
                            {0,6,0,  0,8,0,  0,0,0},

                            {0,7,0,  0,0,0,  0,0,4},
                            {0,0,4,  0,7,0,  6,0,0},
                            {8,0,0,  0,0,0,  0,9,0},

                            {0,0,0,  0,6,0,  0,7,0},
                            {7,0,0,  0,0,5,  9,0,8},
                            {0,1,0,  9,0,0,  0,3,0},
                            //--------------------//
                            {9,0,0,  0,0,0,  0,5,0},
                            {0,8,0,  0,5,6,  0,0,3},
                            {0,0,0,  0,0,4,  8,0,0},

                            {0,0,0,  0,0,0,  9,8,0},
                            {0,6,0,  0,8,0,  0,7,0},
                            {0,2,1,  0,0,0,  0,0,0},

                            {0,0,4,  9,0,0,  0,0,0},
                            {3,0,0,  2,7,0,  0,6,0},
                            {0,5,0,  0,0,0,  0,0,9}};



#endif // PARTIDAS_H_INCLUDED
