#include <iostream>
#include <fstream>
#include <string>

void addShadcnToVueJs(std::string projectName)
{
  std::string pathtoolinstallcommand = "cd " + projectName + " && npm i -D @types/node";
  system(pathtoolinstallcommand.c_str());

  std::ofstream replaceMainFile(projectName + "/src/main.js");
  if (replaceMainFile.is_open())
  {
    replaceMainFile << R"(
import './assets/main.css'
import './assets/index.css'

import { createApp } from 'vue'
import App from './App.vue'

createApp(App).mount('#app')
)";
  }
  else
  {
    std::cout << "Error: Unable to open file" << std::endl;
  }
  std::ofstream replaceViteConfigFile(projectName + "/vite.config.js");
  if (replaceViteConfigFile.is_open())
  {
    replaceViteConfigFile << R"(
import path from 'node:path'
import vue from '@vitejs/plugin-vue'
import { defineConfig } from 'vite'

import tailwind from 'tailwindcss'
import autoprefixer from 'autoprefixer'

export default defineConfig({
  css: {
    postcss: {
      plugins: [tailwind(), autoprefixer()],
    },
  },
  plugins: [vue()],
  resolve: {
    alias: {
      '@': path.resolve(__dirname, './src'),
    },
  },
})        
)";
  }
  else
  {
    std::cout << "Error: Unable to open file" << std::endl;
  }
  std::cout << "When Prompted, choose File Locations Choose Default Settings Otherwise You Will Have To Manually Edit Your Files For Them To Detect Shadcn." << std::endl;
  std::string runshadcninit = "cd " + projectName + " && npx shadcn-vue@latest init";
  system(runshadcninit.c_str());
  std::cout << "Adding Shadcn Button Component To Check Everything Works" << std::endl;
  std::string installshadcnbtn = "cd " + projectName + " && npx shadcn-vue@latest add button";
  system(installshadcnbtn.c_str());
  std::ofstream replaceAppjsFile(projectName + "/src/App.vue");
  if (replaceAppjsFile.is_open())
  {
    replaceAppjsFile << R"(
<script setup>
import { Button } from '@/components/ui/button'
</script>

<template>
  <div class="flex place-items-center justify-center w-screen h-screen">
    <div class="w-[680px] h-[350px] flex place-items-center justify-center flex-col gap-3 bg-card border border-border rounded-lg">
      <h1 class="font-bold text-[27px]">These Project Was Created With Genesis</h1>
      <h2>Modify App.vue File To Disable This Card</h2>
      <Button>Shadcn Button</Button>
    </div>
  </div>
</template>
)";
  }
  else
  {
    std::cout << "Error: Unable to open file" << std::endl;
  }
  std::cout << "Shadcn has been added to your Vue.js project" << std::endl;
}