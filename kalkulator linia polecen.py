import sys

if len(sys.argv) != 4:
    print("Uzycie:")
    print("python 03_kalkulator_linia_polecen.py liczba1 add liczba2")
    exit()

number1 = int(sys.argv[1])
operation = sys.argv[2]
number2 = int(sys.argv[3])

if operation == "add":
    print(f"{number1} + {number2} = {number1 + number2}")
else:
    print("Nieznana operacja")