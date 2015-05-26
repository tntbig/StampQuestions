// Jobs
job_arr = new Array("Accountant","Developer","Model");

function jobSelect(jobElementId) {

    var jobElement = document.getElementById(jobElementId);

    jobElement.length = 0;
    jobElement.options[0] = new Option('Select Job', '');
    jobElement.selectedIndex = 0;

    for (var i = 0; i < job_arr.length; i++) {
        jobElement.options[jobElement.length] = new Option(job_arr[i], job_arr[i]);
    }
}