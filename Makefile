CC = g++   # 编译器，你也可以使用 gcc 替代 g++，具体根据你的需要选择

SOURCES := $(wildcard *.cpp *.c)   # 获取当前文件夹中的所有 .cpp 和 .c 文件
EXECS := $(SOURCES:.cpp=) $(SOURCES:.c=)   # 将源文件列表转换为对应的可执行文件列表

all: $(EXECS)

%: %.cpp %.c
	$(CC) $< -o $@   # 编译单个源文件为可执行文件

run: 

clean:
	rm -f $(EXECS)   # 清理编译产生的可执行文件
