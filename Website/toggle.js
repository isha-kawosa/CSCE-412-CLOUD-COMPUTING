function toggleStyleSheet(){

    var element = document.getElementById("firstsheet");
    var currentstyle= element.getAttribute("href");
    var newstyle=" ";
    if(currentstyle== "landingstyle.css"){
        element.setAttribute("href", "secondstyle.css")
        newstyle= "secondstyle.css";
    }
    else{
        element.setAttribute("href", "landingstyle.css")
        newstyle= "landingstyle.css";
    }

    localStorage.setItem("newstyle", newstyle)
    
    var styleToggle = document.getElementById('theme-toggle');
    styleToggle.classList.toggle('toggled');
   
    if (styleToggle.checked) {
        localStorage.setItem("theme", "dark");
    } else {
        localStorage.setItem("theme", "light");
    }

}


window.onload = function(){
    
    var style= localStorage.getItem("newstyle");
    var element = document.getElementById("firstsheet");
    if(style!=null){
        element.setAttribute("href", style)
    }
   
    var theme = localStorage.getItem("theme");
    var themeToggle = document.getElementById('theme-toggle');

    if (theme === "dark") {
        themeToggle.checked = true;
    } else {
        themeToggle.checked = false;
    }
}