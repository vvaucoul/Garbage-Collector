# Garbage-Collector
A little garbage Collector Library in C. <br>
It allows you to free allocated memory easily.

## Code Example

<img align="left" src="https://user-images.githubusercontent.com/66129673/189103700-3e611866-8f0a-4eb6-8b22-72a5641784b6.png" width=45% height=45%>
<img src="https://user-images.githubusercontent.com/66129673/189104460-f736d7a9-f427-45e4-a1be-bab53cf89e21.png" width=45% height=45%>

## Installation

```sh
➜ git clone https://github.com/vvaucoul/Garbage-Collector
➜ make
➜ sudo make install
```

## Uninstall

```sh
➜ git clone https://github.com/vvaucoul/Garbage-Collector
➜ sudo make uninstall
```
## Usage

- You must use theses allocators:

```C
vmalloc();
vcalloc();
vrealloc();
```

- To free a pointer

```C
vfree();
```

- Anywhere in your code, you can free all your pointers with this function

```C
gc_clean();
```

- Usefull functions:

```C
vdefragment();
```

