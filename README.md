# Servidor (Sockets TCP em C) 🖧

Lado **servidor** de uma aplicação **cliente-servidor** de **locadora de filmes**, baseada em **sockets TCP/IP** e escrita em **C**. Mantém um catálogo de filmes e atende às requisições dos clientes (consulta e locação).

## ✨ Características

- Comunicação via **socket TCP** (`SOCK_STREAM`), escutando na **porta 1200** (`#define PORT 1200`)
- Código **multiplataforma**: usa `winsock.h` no Windows e sockets POSIX no Linux/Unix
- Catálogo de filmes em memória (`struct Filmes` com nome, **status** e **nº de locações**)
- Acervo inicial: **Matrix**, **Hércules** e **Pânico** (todos "Disponível")
- Recebe operação + código do cliente e responde com os dados do filme

## 🗂️ Modelo de dados

```c
struct Filmes {
    char Filme;       // título
    char Status;      // disponibilidade
    int  n_locacoes;  // contador de locações
};
```

## 🛠️ Tecnologias

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)

- **C** + API de **sockets** (Winsock / Berkeley sockets)

## 🚀 Como executar

```bash
# Linux
gcc servidor.c -o servidor
./servidor

# Windows (MinGW)
gcc servidor.c -o servidor -lwsock32
```

## 🔗 Cliente

Use junto com o repositório [`Cliente`](https://github.com/limongi1234/Cliente), que faz as requisições a este servidor.

> ⚠️ **Atenção:** no código original, o servidor escuta na porta **1200** e o cliente conecta na porta **2000** — para que se comuniquem, ajuste uma das duas para que coincidam.
