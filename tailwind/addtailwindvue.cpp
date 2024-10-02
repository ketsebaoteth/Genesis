#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>

void addTailwindToVueJs(std::string projectName)
{
    // command to install tailwindcss autoprefixer postcss
    std::string command = "cd " + projectName + " && npm install -D tailwindcss@latest postcss@latest autoprefixer@latest";
    system(command.c_str());
    // modify tailwind.config.js
    std::ofstream tailwindConfigFile(projectName + "/tailwind.config.js");
    if (tailwindConfigFile.is_open())
    {
        tailwindConfigFile << R"(
/** @type {import('tailwindcss').Config} */
export default {
  content: [
    './src/**/*.html',
    './src/**/*.vue',
  ],
  theme: {
    extend: {
      colors:{
        background: "#FFF7D8",
      },
      fontFamily: {
        libre: ['Libre Bodoni'],
        caslon: ['Libre Caslon Text'],
        antikua: ["Inknut Antiqua"]
      }
    },
  },
  plugins: [],
}
)";
    }
    else
    {
        std::cerr << "Error: Unable to create tailwind.config.js file" << std::endl;
    }
    // modify package.json
    std::ofstream packageJsonFile(projectName + "/package.json");
    if (packageJsonFile.is_open())
    {
        packageJsonFile << R"(
{
  "name": "package.json",
  "version": "0.0.0",
  "private": true,
  "type": "module",
  "scripts": {
    "dev": "vite",
    "build": "vite build",
    "preview": "vite preview"
  },
  "dependencies": {
    "gsap": "^3.12.5",
    "vue": "^3.4.29"
  },
  "devDependencies": {
    "@vitejs/plugin-vue": "^5.0.5",
    "autoprefixer": "^10.4.20",
    "tailwindcss": "^3.4.13",
    "vite": "^5.3.1"
  }
}
)";
    }
    else
    {
        std::cerr << "Error: Unable to create package.json file" << std::endl;
    }
    // modify vite.config.js
    std::ofstream viteConfigFile(projectName + "/vite.config.js");
    if (viteConfigFile.is_open())
    {
        viteConfigFile << R"(
import { fileURLToPath, URL } from 'node:url'

import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'


import tailwind from 'tailwindcss'
import autoprefixer from 'autoprefixer'

// https://vitejs.dev/config/
export default defineConfig({
  css: {
    postcss: {
      plugins: [tailwind(), autoprefixer()],
    },
  },
  plugins: [
    vue(),
  ],
  resolve: {
    alias: {
      '@': fileURLToPath(new URL('./src', import.meta.url))
    }
  }
})
)";
    }
    else
    {
        std::cerr << "Error: Unable to create vite.config.js file" << std::endl;
    }
    // modify main.css
    std::ofstream mainCssFile(projectName + "/src/assets/main.css");
    if (mainCssFile.is_open())
    {
        mainCssFile << R"(
@tailwind base;
@tailwind components;
@tailwind utilities;
)";
    }
    else
    {
        std::cerr << "Error: Unable to create main.css file" << std::endl;
    }
    // modify appjs
    std::ofstream appJsFile(projectName + "/src/App.vue");
    if (appJsFile.is_open())
    {
        appJsFile << R"(
<script setup>
</script>

<template>
    <div class="container w-screen h-screen flex place-items-center justify-center">
        <h1>Vuejs+tailwindcss Project With Genesis!</h1>
    </div>
</template>

<style scoped>

</style>
)";
    }
    else
    {
        std::cerr << "Error: Unable to create App.vue file" << std::endl;
    }
}