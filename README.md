# MyTime
I want my own way to deal with datetimes that doesn't suck

Goals: 
- records year, month, day, hour, quarter, timezone
- does so in the space of a single int
- has member functions to get year, month, day, hour, quarter, timezone
- also " to get weekday
- mytime subtraction and float addition supported (yeah it's getting weird)
- initializtions don't suck somehow
- whatever else I want

 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31

[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]

{         year         }{   month  }{     day     }{    hours    }{ q  }{ fm }{    timezone    }

Let's think about this
- 256 years = 8 bits
- 12 months = 4 bits
- 31 days = 5 bits
- 24 hours = 5 bits
- 4 quarters = 2 bits
- 3 femtoids = 2 bits
- 37 timezones = 6 bits
total: 32 bits 

# Oh yeah, it's all coming together

example: 16:20 April 20, 1969 time zone 12 (that doesn't mean anything yet)
69 - 4 - 20 - 16 - 1 - 1 - 12
01000101 - 0100 - 10100 - 10000 - 01 - 01 - 001100
01000101010010100100000101001100
1162494284