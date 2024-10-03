#include <iostream>
#include <fstream>
#include <string>

void addShadcnToVueJs(std::string projectName)
{
    std::string pathtoolinstallcommand = "cd " + projectName + " && npm i -D @types/node";
    system(pathtoolinstallcommand.c_str());
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
    std::cout << "Adding Shadcn to Vue.js choose main.css file inside of src/assets/css/main.css" << std::endl;
    std::string runshadcninit = "cd " + projectName + " && npx shadcn-vue@latest init";
    system(runshadcninit.c_str());
    std::cout << "Adding Shadcn to Vue.js choose button component" << std::endl;
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
  <div>
    <Button>Click me</Button>
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