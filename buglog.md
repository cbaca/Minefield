# BUG LOG
Throws when accessing range larger than 10 of minefield larger than 10
SEGFAULT when placing a mine outside of bounds
For MINE_HIDDEN at (x, y), get(x,y) does't return MINE_SHOWN after revealAdjancent(x, y+1) is called.
