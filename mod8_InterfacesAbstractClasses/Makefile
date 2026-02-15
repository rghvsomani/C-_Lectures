# Makefile for Interface vs Abstract Class Tutorial
# Compiles all examples and creates executable

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra
TARGET = program
SOURCES = AbstractShape.cpp ConcreteShapes.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build successful! Run with: ./$(TARGET)"

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Cleaned build artifacts"

# Show help
help:
	@echo "Available targets:"
	@echo "  make         - Build the program"
	@echo "  make run     - Build and run the program"
	@echo "  make clean   - Remove build artifacts"
	@echo "  make help    - Show this help message"

.PHONY: all run clean help
