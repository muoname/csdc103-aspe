all: bonus

bonus: bonus.cpp
	g++ bonus.cpp -o bonus
	
test: bonus.in
	./bonus < bonus.in > bonus.out
	
clean: 
	rm -rf bonus