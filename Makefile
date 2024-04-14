main : main.cpp
	$(CXX) -o $@ $<
	@./main

run :
	./main

clean:
	@rm main
