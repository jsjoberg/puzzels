package main

import "fmt"

// https://en.wikipedia.org/wiki/Primality_test#Python_Code
func isPrime(n int) bool {
	if n <= 3 {
		return n > 1
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	for i := 5; i*i <= n; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

func main() {
	a := 0
	for i := 0; i < 2_000_000; i++ {
		if isPrime(i) {
			a += i
		}
	}
	fmt.Println(a)
}
