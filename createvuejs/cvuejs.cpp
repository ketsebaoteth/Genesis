#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>

void createVueJsProject(std::string projectName)
{
  std::filesystem::create_directory(projectName);
  std::filesystem::create_directories(projectName + "/src");
  std::filesystem::create_directories(projectName + "/public");
  std::filesystem::create_directories(projectName + "/src/assets");
  std::filesystem::create_directories(projectName + "/src/components");
  std::filesystem::create_directories(projectName + "/src/components/icons");
  // create a .gitignore file
  std::ofstream gitignoreFile(projectName + "/.gitignore");
  if (gitignoreFile.is_open())
  {
    gitignoreFile << R"(
# Logs
logs
*.log
npm-debug.log*
yarn-debug.log*
yarn-error.log*
pnpm-debug.log*
lerna-debug.log*

node_modules
.DS_Store
dist
dist-ssr
coverage
*.local

/cypress/videos/
/cypress/screenshots/

# Editor directories and files
.vscode/*
!.vscode/extensions.json
.idea
*.suo
*.ntvs*
*.njsproj
*.sln
*.sw?

*.tsbuildinfo
)";
  }
  else
  {
    std::cerr << "Error: Unable to create .gitignore file" << std::endl;
  }
  // create a index.html file
  std::ofstream indexHtmlFile(projectName + "/index.html");
  if (indexHtmlFile.is_open())
  {
    indexHtmlFile << R"(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <link rel="icon" href="/favicon.ico" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="preconnect" href="https://fonts.googleapis.com" />
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
    <link
      href="https://fonts.googleapis.com/css2?family=Inknut+Antiqua:wght@300;400;500;600;700;800;900&family=Libre+Caslon+Text:ital,wght@0,400;0,700;1,400&display=swap"
      rel="stylesheet"
    />
    <title>Vite App</title>
  </head>
  <body>
    <div id="app"></div>
    <script type="module" src="/src/main.js"></script>
  </body>
</html>
)";
  }
  else
  {
    std::cerr << "Error: Unable to create index.html file" << std::endl;
  }
  // create a jsconfig.json file
  std::ofstream jsconfigJsonFile(projectName + "/jsconfig.json");
  if (jsconfigJsonFile.is_open())
  {
    jsconfigJsonFile << R"(
{
  "compilerOptions": {
    "paths": {
      "@/*": ["./src/*"]
    }
  },
  "exclude": ["node_modules", "dist"]
}
)";
  }
  else
  {
    std::cerr << "Error: Unable to create jsconfig.json file" << std::endl;
  }
  // create a package.json file
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
    "vite": "^5.3.1"
  }
}
)";
  }
  else
  {
    std::cerr << "Error: Unable to create package.json file" << std::endl;
  }
  // create a README.md file
  std::ofstream readmeMdFile(projectName + "/README.md");
  if (readmeMdFile.is_open())
  {
    readmeMdFile << "# " + projectName + R"(
# How to run
1. Clone the repository
`git clone Repository_link`
2. Install the dependencies
`npm install`
3. Run the development server
`npm run dev`

## Project Was Generated Using Genesis －O－
)";
  }
  else
  {
    std::cerr << "Error: Unable to create README.md file" << std::endl;
  }
  // create a vite config file
  std::ofstream viteConfigFile(projectName + "/vite.config.js");
  if (viteConfigFile.is_open())
  {
    viteConfigFile << R"(
import { fileURLToPath, URL } from 'node:url'

import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [
    vue(),
  ],
})
)";
  }
  else
  {
    std::cerr << "Error: Unable to create vite.config.js file" << std::endl;
  }
  // create a mainjs file
  std::ofstream mainjs(projectName + "/src/main.js");
  if (mainjs.is_open())
  {
    mainjs << R"(
import './assets/main.css'

import { createApp } from 'vue'
import App from './App.vue'

createApp(App).mount('#app')
)";
  }
  else
  {
    std::cerr << "Error: Unable to create main.js file " << std::endl;
  }
  std::ofstream appvue(projectName + "/src/App.vue");
  if (appvue.is_open())
  {
    appvue << R"(
<script setup>
</script>

<template>
    <div class="container">
        <h1>Vuejs Project With Genesis!</h1>
    </div>
</template>

<style scoped>
.container{
    width: 100vw;
    height: 100vh;
    display: flex;
    place-items: center;
    justify-content: center;
}
</style>
        
)";
  }
  else
  {
    std::cerr << "Error: Unable to create App.vue file " << std::endl;
  }
  std::ofstream maincss(projectName + "/src/assets/main.css");
  if (maincss.is_open())
  {
    maincss << R"(
/* You can customize this file */
)";
  }
  else
  {
    std::cerr << "Error: Unable to create main.css file " << std::endl;
  }
  std::cout << "Project created successfully!" << std::endl;
}