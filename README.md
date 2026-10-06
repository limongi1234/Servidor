# Servidor (Sockets TCP em C) 🖧

Lado **servidor** de uma aplicação **cliente-servidor** de **locadora de filmes**, baseada em **sockets TCP/IP** e escrita em **C**. Mantém um catálogo de filmes e atende às requisições dos clientes (consulta e locação).

## ✨ Características

- Comunicação via **socket TCP** (`SOCK_STREAM`), escutando na **porta 2000**
- Feito para **Windows** (Winsock), como projeto do **Dev-C++**
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

Abra o projeto `servidor.dev` no **Dev-C++** e compile, ou use o MinGW no Windows:

```bash
gcc servidor.c -o servidor -lwsock32
servidor.exe
```

## 🔗 Cliente

Use junto com o repositório [`Cliente`](https://github.com/limongi1234/Cliente), que faz as requisições a este servidor.

Inicie o servidor primeiro; os dois usam a porta **2000**.
