numbers = [1, 2, 3, -4, 50, 6, 7, 8, 9, 10]

numbers.sort()

print("Posortowana tablica:")
print(numbers)

n = len(numbers)

if n % 2 == 0:
    median = (numbers[n // 2 - 1] + numbers[n // 2]) / 2
else:
    median = numbers[n // 2]

print("Mediana:", median)

print("Minimum:", min(numbers))
print("Maximum:", max(numbers))
print("Suma:", sum(numbers))
print("Srednia:", sum(numbers) / len(numbers))