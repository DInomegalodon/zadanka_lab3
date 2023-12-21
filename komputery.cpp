#include <iostream>
#include <string>
// Product class
class Computer {
public:
	void setCPU(const std::string& cpu) {
		cpu_ = cpu;
	}
	void setMemory(const std::string& memory) {
		memory_ = memory;
	}
	void setStorage(const std::string& storage) {
		storage_ = storage;
	}
	void display() {
		std::cout << "CPU: " << cpu_ << std::endl;
		std::cout << "Memory: " << memory_ << std::endl;
		std::cout << "Storage: " << storage_ << std::endl;
	}
private:
	std::string cpu_;
	std::string memory_;
	std::string storage_;
};

class Laptop {
public:
	void setCPU(const std::string& cpu) {
		cpu_ = cpu;
	}
	void setMemory(const std::string& memory) {
		memory_ = memory;
	}
	void setStorage(const std::string& storage) {
		storage_ = storage;
	}
	void setMonitor(const std::string& monitor) {
		monitor_ = monitor;
	}
	void display() {
		std::cout << "CPU: " << cpu_ << std::endl;
		std::cout << "Memory: " << memory_ << std::endl;
		std::cout << "Storage: " << storage_ << std::endl;
		std::cout << "Monitor: " << monitor_ << std::endl;
	}
private:
	std::string cpu_;
	std::string memory_;
	std::string storage_;
	std::string monitor_;
};
// Builder interface
class ComputerBuilder {
public:
	virtual void buildCPU(const std::string& cpu) = 0;
	virtual void buildMemory(const std::string& memory) = 0;
	virtual void buildStorage(const std::string& storage) = 0;
	//virtual void buildMoniotor(const std::string& storage) = 0;
	virtual Computer getResult() = 0;
};

class LaptopBuilder {
public:
	virtual void buildCPU(const std::string& cpu) = 0;
	virtual void buildMemory(const std::string& memory) = 0;
	virtual void buildStorage(const std::string& storage) = 0;
	virtual void buildMoniotor(const std::string& storage) = 0;
	virtual Laptop getResult() = 0;
};
// Concrete Builder
class DesktopComputerBuilder : public ComputerBuilder {
public:
	DesktopComputerBuilder() {
		computer_ = Computer();
	}
	void buildCPU(const std::string& cpu) override {
		computer_.setCPU(cpu);
	}
	void buildMemory(const std::string& memory) override {
		computer_.setMemory(memory);
	}
	void buildStorage(const std::string& storage) override {
		computer_.setStorage(storage);
	}
	Computer getResult() override {
		return computer_;
	}
private:
	Computer computer_;
};
/*
class LaptopComputerBuilder : public LaptopBuilder {
public:
	LaptopComputerBuilder() {
		laptop_ = Laptop();
	}
	void buildCPU(const std::string& cpu) override {
		laptop_.setCPU(cpu);
	}
	void buildMemory(const std::string& memory) override {
		laptop_.setMemory(memory);
	}
	void buildStorage(const std::string& storage) override {
		laptop_.setStorage(storage);
	}
	void buildMoniotor(const std::string & monitor) {
		laptop_.setMonitor(monitor);
	}
	Laptop getResult() override {
		return laptop_;
	}
private:
	Laptop laptop_;
};
*/
class LaptopComputerBuilder : public ComputerBuilder {
public:
	LaptopComputerBuilder() {
		computer_ = Computer();
	}
	void buildCPU(const std::string& cpu) override {
		computer_.setCPU(cpu);
	}
	void buildMemory(const std::string& memory) override {
		computer_.setMemory(memory);
	}
	void buildStorage(const std::string& storage) override {
		computer_.setStorage(storage);
	}
	Computer getResult() override {
		return computer_;
	}
private:
	Computer computer_;
};

// Director
class ComputerAssembler {
public:
	Computer assembleComputer(ComputerBuilder& builder) {
		builder.buildCPU("Intel i7");
		builder.buildMemory("16GB");
		builder.buildStorage("512GB SSD");
		return builder.getResult();
	}
};

class LaptopAssembler {
public:
	Laptop assembleLaptop(LaptopBuilder& builder) {
		builder.buildCPU("Intel i7");
		builder.buildMemory("16GB");
		builder.buildStorage("512GB SSD");
		builder.buildMoniotor("MSI 27'");
		return builder.getResult();
	}
};

class LaptopAssembler2 {
public:
	Computer assembleLaptop(ComputerBuilder& builder) {
		builder.buildCPU("Intel i3");
		builder.buildMemory("4GB");
		builder.buildStorage("256GB SSD");
		return builder.getResult();
	}
};
int main() {
	DesktopComputerBuilder desktopBuilder;
	ComputerAssembler assembler;
	Computer desktop = assembler.assembleComputer(desktopBuilder);
	std::cout << "Desktop Computer Configuration:" << std::endl;
	desktop.display();
	std::cout << "\n\n";
	/*
	LaptopComputerBuilder laptopBuilder;
	LaptopAssembler assembler1;
	Laptop laptop = assembler1.assembleLaptop(laptopBuilder);
	std::cout << "Laptop Computer Configuration:" << std::endl;
	laptop.display();
	*/
	LaptopComputerBuilder laptopBuilder;
	LaptopAssembler2 assembler2;
	Computer laptop = assembler2.assembleLaptop(laptopBuilder);
	std::cout << "Laptop Computer Configuration:" << std::endl;
	laptop.display();
	
	return 0;
}